#include "../include/WebServ.hpp"
#include <stdexcept>
#include <cerrno>

bool ServerManager::_running = true;

ClientRequest::ClientRequest()
    : buffer(""), max_size(0), current_size(0), content_length(-1), is_chunked(false),
      header_end(std::string::npos), body_start(0),
      request_path(""), method(""), headers_parsed(false), discard_body(false) {}

void ClientRequest::append_to_buffer(const std::string &chunk)
{
    buffer += chunk;
    current_size += chunk.size();
}

ServerManager::ServerManager()
    : _max_fd(0)
{
}

ServerManager::~ServerManager() {}

void ServerManager::setup(const std::vector<ServerUnit> &configs)
{

    _servers = configs;

    for (size_t i = 0; i < _servers.size(); ++i)
    {
        ServerUnit &server = _servers[i];
        bool reused = false;

        for (size_t j = 0; j < i; ++j)
        {
            const ServerUnit &prev = _servers[j];
            if (prev.getHost() == server.getHost() &&
                prev.getPort() == server.getPort())
            {
                server.setFd(prev.getFd());
                reused = true;
                break;
            }
        }

        if (!reused)
        {
            server.setUpIndividualServer();
        }

        _servers_map[server.getFd()] = server;

        char ipbuf[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &server.getHost(), ipbuf, sizeof(ipbuf));
        logInfo(
            "Server %s bound to http://%s:%d, fd = %d",
            server.getServerName().c_str(),
            ipbuf,
            server.getPort(),
            server.getFd());
    }
}
void ServerManager::_init_server_unit(ServerUnit &server)
{
    const int fd = server.getFd();
    if (listen(fd, BACKLOG_SIZE) < 0)
    {
        const int err = errno;
        logError("listen(%d) failed: %s", fd, strerror(err));
        close(fd);
        _servers_map.erase(fd);
        throw std::runtime_error("listen failed");
    }

    FD_SET(fd, &_read_fds);
    if (fd > _max_fd)
        _max_fd = fd;

    logInfo("Server started on port %d", server.getPort());
}

int ServerManager::_get_client_server_fd(int client_socket) const
{
    std::map<int, int>::const_iterator it = _client_server_map.find(client_socket);
    if (it == _client_server_map.end())
    {
        return -1;
    }
    return it->second;
}

void ServerManager::init()
{
    _running = true;
    signal(SIGINT, ServerManager::_handle_signal);

    FD_ZERO(&_read_fds);
	FD_ZERO(&_write_fds);

    for (size_t i = 0; i < _servers.size(); ++i)
        _init_server_unit(_servers[i]);

    fd_set temp_read_fds;
    fd_set temp_write_fds;
    while (_running) {
        temp_read_fds = _read_fds;
        temp_write_fds = _write_fds;

        int activity = select(_max_fd + 1, &temp_read_fds, &temp_write_fds, NULL, NULL);
        if (activity < 0) {
            if (errno == EINTR)
                continue;
            logInfo("Failed to select on sockets");
            continue;
        }
        if (activity == 0)
            continue;

        for (int fd = 0; fd <= _max_fd; ++fd) {
            bool handled = false;
            if (FD_ISSET(fd, &temp_read_fds)) {
                if (_servers_map.find(fd) != _servers_map.end()) {
                    _handle_new_connection(fd);
                } else {
                    _handle_read(fd);
                }
                handled = true;
            }
            if (!handled && FD_ISSET(fd, &temp_write_fds)) {
                _handle_write(fd);
            }
        }
    }
    logInfo("\nServers shutting down...");
}

void ServerManager::_handle_new_connection(int listening_socket)
{
    int client_sock = accept(listening_socket, NULL, NULL);
    if (client_sock < 0)
    {
        logError("Failed to accept new connection on socket %d: %s", listening_socket, strerror(errno));
        return;
    }

    if (client_sock >= FD_SETSIZE)
    {
        logError("Too many open files, cannot accept new connection on socket %d", listening_socket);
        close(client_sock);
        return;
    }

    set_nonblocking(client_sock);
    FD_SET(client_sock, &_read_fds);
    if (client_sock > _max_fd)
        _max_fd = client_sock;

    _client_server_map[client_sock] = listening_socket;
    _read_requests[client_sock] = ClientRequest();
    _write_buffer[client_sock] = "";
    _bytes_sent[client_sock] = 0;
}

void ServerManager::_handle_write(int client_sock) {

    std::string remaining_response = _write_buffer[client_sock].substr(_bytes_sent[client_sock]);

    logInfo("Sending response to client socket %d", client_sock);
    ssize_t n = send(client_sock, remaining_response.c_str(), remaining_response.size(), 0);

    if (n < 0) {
        _cleanup_client(client_sock);
        logError("Failed to send data to client socket %d. Connection closed.", client_sock);
        return;
    }
    if (n == 0)
    {
        _cleanup_client(client_sock);
        logError("Failed to send data to client socket %d: peer closed connection.", client_sock);
        return;
    }
    _bytes_sent[client_sock] += static_cast<size_t>(n);
    if (_bytes_sent[client_sock] == _write_buffer[client_sock].size()) {
       if (_should_close_connection(_read_requests[client_sock].buffer, _write_buffer[client_sock])) {
            _cleanup_client(client_sock);
        } else {
            _read_requests[client_sock] = ClientRequest();
            _write_buffer[client_sock].clear();
            _bytes_sent[client_sock] = 0;
            FD_CLR(client_sock, &_write_fds);
            FD_SET(client_sock, &_read_fds);
        }
    }
}

bool ServerManager::_should_close_connection(const std::string &request, const std::string &response)
{
    bool closing = false;
    if (in_str(request, "Connection: close"))
    {
        logError("🐠 Closing connection (requested)");
        closing = true;
    }
    if (in_str(response, "Connection: close"))
    {
        logError("🐠 Closing connection (response)");
        closing = true;
    }
    return closing;
}

bool ServerManager::parse_headers(int client_sock, ClientRequest &cr)
{
    cr.header_end = cr.buffer.find("\r\n\r\n");
    if (cr.header_end == std::string::npos)
        return false;
    cr.body_start = cr.header_end + 4;

    size_t line_end = cr.buffer.find("\r\n");
    if (line_end == std::string::npos)
        return false;
    std::string req_line = cr.buffer.substr(0, line_end);
    {
        size_t sp1 = req_line.find(' ');
        size_t sp2 = (sp1 == std::string::npos) ? std::string::npos : req_line.find(' ', sp1 + 1);
        if (sp1 != std::string::npos && sp2 != std::string::npos)
        {
            cr.method = req_line.substr(0, sp1);
            cr.request_path = req_line.substr(sp1 + 1, sp2 - sp1 - 1);
        }
    }
    cr.content_length = -1;
    size_t pos = line_end + 2;
    while (pos < cr.header_end)
    {
        size_t next = cr.buffer.find("\r\n", pos);
        if (next == std::string::npos || next > cr.header_end)
            break;
        std::string line = cr.buffer.substr(pos, next - pos);
        size_t colon = line.find(':');
        if (colon != std::string::npos)
        {
            std::string key = line.substr(0, colon);
            std::string val = line.substr(colon + 1);
            strip(key, ' ');
            strip(val, ' ');
            if (ci_equal(key, "Content-Length"))
            {
                cr.content_length = strtol(val.c_str(), NULL, 10);
                if (cr.content_length < 0)
                    cr.content_length = -1;
            }
            if (ci_equal(key, "Transfer-Encoding"))
            {
                std::string lower = val;
                to_lower(lower);
                if (lower.find("chunked") != std::string::npos)
                {
                    cr.is_chunked = true;
                }
            }
        }
        pos = next + 2;
    }
    int server_fd = _get_client_server_fd(client_sock);
    if (server_fd < 0)
    {
        logError("Could not find server for client socket %d", client_sock);
        return false;
    }
    ServerUnit &server = _servers_map[server_fd];
    const Location *loc = _find_best_location(cr.request_path, server.getLocations());
    if (loc)
        cr.max_size = loc->getMaxBodySize();
    else
        cr.max_size = server.getClientMaxBodySize();

    cr.headers_parsed = true;

    if (cr.max_size > 0 && cr.content_length >= 0 && (size_t)cr.content_length > cr.max_size)
    {
        logError("Payload declared too large: CL=%ld > limit=%zu",
                 cr.content_length, cr.max_size);
    }
    return true;
}

void ServerManager::_handle_read(int client_sock)
{
    char buffer[BUFFER_SIZE];

    logInfo("Client connected on socket %d", client_sock);
    ClientRequest &cr = _read_requests[client_sock];

    int n = recv(client_sock, buffer, sizeof(buffer), 0);
    if (n > 0)
    {
        if (cr.discard_body)
        {
            return;
        }

        cr.append_to_buffer(std::string(buffer, n));

        if (!cr.headers_parsed)
        {
            if (!parse_headers(client_sock, cr))
            {
                return;
            }
            if (cr.max_size > 0 && cr.content_length >= 0 && (size_t)cr.content_length > cr.max_size)
            {
                logError("Client %d Content-Length %ld exceeds max_size %zu. Sending 413.",
                         client_sock, cr.content_length, cr.max_size);
                _write_buffer[client_sock] =
                    "HTTP/1.1 413 Payload Too Large\r\n"
                    "Content-Type: text/html\r\n"
                    "Content-Length: 30\r\n"
                    "Connection: close\r\n\r\n"
                    "<h1>413 Payload Too Large</h1>";
                _bytes_sent[client_sock] = 0;
                cr.discard_body = true;
                FD_CLR(client_sock, &_read_fds);
                FD_SET(client_sock, &_write_fds);
                return;
            }
        }

        if (cr.headers_parsed)
        {
            size_t body_bytes = (cr.current_size > cr.body_start)
                                    ? (cr.current_size - cr.body_start)
                                    : 0;

            if (cr.max_size > 0 && body_bytes > cr.max_size)
            {
                logError("Client %d exceeded max body size (body=%zu > %zu). 413.",
                         client_sock, body_bytes, cr.max_size);
                _write_buffer[client_sock] =
                    "HTTP/1.1 413 Payload Too Large\r\n"
                    "Content-Type: text/html\r\n"
                    "Connection: close\r\n\r\n"
                    "<h1>413 Payload Too Large</h1>";
                _bytes_sent[client_sock] = 0;
                FD_CLR(client_sock, &_read_fds);
                FD_SET(client_sock, &_write_fds);
                return;
            }

            bool complete = false;
            if (cr.content_length < 0)
            {
                complete = true;
            }
            else
            {
                complete = (body_bytes >= (size_t)cr.content_length);
            }
            if (complete)
            {
                logInfo("Request complete from client socket %d", client_sock);
                _write_buffer[client_sock] = prepare_response(client_sock, cr.buffer);
                _bytes_sent[client_sock] = 0;
                FD_CLR(client_sock, &_read_fds);
                FD_SET(client_sock, &_write_fds);
                return;
            }
        }
        return;
    }


    if (n == 0) {
        if (cr.headers_parsed) {
            size_t body_bytes = (cr.current_size > cr.body_start)
                                ? (cr.current_size - cr.body_start)
                                : 0;
            if (cr.content_length < 0 || body_bytes >= (size_t)cr.content_length) {
                logInfo("Request complete from client socket %d (on close)", client_sock);
                _write_buffer[client_sock] = prepare_response(client_sock, cr.buffer);
            } else {
                _cleanup_client(client_sock);
            }
        } else {
            _cleanup_client(client_sock);
        }
        return;
    }
}

bool ServerManager::_request_complete(const ClientRequest &clrequest)
{
    const std::string &request = clrequest.buffer;
    size_t header_end = request.find("\r\n\r\n");
    if (header_end == std::string::npos)
        return false;

    int content_length = clrequest.content_length;
    if (clrequest.headers_parsed && content_length == 0)
        return true;

    size_t body_start = header_end + 4;
    size_t body_size = clrequest.current_size - body_start;

    return body_size >= (size_t)content_length;
}

bool ServerManager::_try_drain_and_adjust_response(int client_socket, std::string &response_str)
{
    (void)response_str;
    std::map<int, ClientRequest>::iterator it = _read_requests.find(client_socket);
    if (it == _read_requests.end())
        return false;
    ClientRequest &cr = it->second;
    if (!(cr.is_chunked || cr.content_length >= 0))
        return true;

    return false;
}

const Location *ServerManager::_find_best_location(const std::string &request_path, const std::vector<Location> &locations) const
{
    const Location *best_match = NULL;
    size_t best_len = 0;

    for (size_t i = 0; i < locations.size(); ++i)
    {
        const Location &loc = locations[i];

        std::string loc_path = loc.getPathLocation();
        if (path_matches(loc_path, request_path))
        {
            if (loc_path.size() > best_len)
            {
                best_match = &loc;
                best_len = loc_path.size();
            }
        }
    }
    return best_match;
}
void ServerManager::_apply_location_config(
    const Location *loc,
    std::string &root,
    std::string &index,
    bool &autoindex,
    std::string &full_path,
    const std::string &request_path,
    const std::string &request_method,
    bool &used_alias)
{
    if (!loc)
        return;
    if (!loc->getMethods()[method_toEnum(request_method)])
    {
        std::string methods = loc->getPrintMethods();
        throw HttpExceptionNotAllowed(methods);
    }
    if (!loc->getRootLocation().empty())
        root = loc->getRootLocation();
    if (!loc->getAlias().empty())
    {
        full_path = loc->getAlias() + request_path.substr(loc->getPathLocation().size());
        used_alias = true;
    }
    if (!loc->getIndexLocation().empty())
        index = loc->getIndexLocation();
    if (loc->getAutoindex() != autoindex)
        autoindex = loc->getAutoindex();
}

void ServerManager::_handle_directory_case(
    std::string &full_path,
    const std::string &request_path,
    const std::string &index,
    bool autoindex,
    Request &request)
{
    if (ConfigFile::getTypePath(full_path) != F_DIRECTORY)
        return;
    if (!request_path.empty() && request_path[request_path.size() - 1] != '/')
    {
        std::string new_location = request_path + "/";
        throw HttpExceptionRedirect(HttpStatusCode::MovedPermanently, new_location);
    }
    if (!index.empty())
    {
        std::string index_path = full_path + index;
        if (ConfigFile::getTypePath(index_path) == F_REGULAR_FILE)
        {
            full_path = index_path;
            return;
        }
    }
    if (autoindex)
    {
        request.setAutoindex(true);
    }
    else
    {
        throw HttpException(HttpStatusCode::NotFound);
    }
}

void ServerManager::_apply_redirection(const Location *loc)
{
    if (loc && !loc->getReturn().empty())
    {
        std::string new_location = loc->getReturn();
        throw HttpExceptionRedirect(HttpStatusCode::MovedPermanently, new_location);
    }
}

void ServerManager::resolve_path(Request &request, int client_socket)
{
    int server_fd = _get_client_server_fd(client_socket);
    if (server_fd == -1)
    {
        logError("resolve_path: client_socket %d not found in _client_server_map!", client_socket);
        throw HttpException(HttpStatusCode::InternalServerError);
    }

    ServerUnit &server = _servers_map[server_fd];
    std::string path = request.getPath();
    path = path_normalization(clean_path(path));

    std::string root = server.getRoot();
    std::string index = server.getIndex();
    bool autoindex = server.getAutoindex();
    bool used_alias = false;
    std::string full_path;

    const Location *loc = _find_best_location(path, server.getLocations());
    _apply_redirection(loc);
    _apply_location_config(loc, root, index, autoindex, full_path, path, request.getMethod(), used_alias);
    request.setMatchedLocation(loc);

    if (!used_alias)
        full_path = root + path;

    _handle_directory_case(full_path, path, index, autoindex, request);

    request.setPath(full_path);
}

std::string ServerManager::prepare_response(int client_socket, const std::string &request_str)
{
    std::string response_str;

    try
    {
        Request request(request_str);
        if (request.getRet() != 200)
            throw HttpException(request.getRet());
        resolve_path(request, client_socket);
        HttpResponse response(&request);
        response_str = response.getResponse();
        logInfo("response_str ok");
    }
    catch (const HttpExceptionRedirect &e)
    {
        int code = e.getStatusCode();
        std::string location = e.getLocation();
        logInfo("Acción: Redirigir con código %d a %s", code, location.c_str());
        HttpResponse response(code, location);
        response_str = response.getResponse();
        logInfo("response_str redirect ok");
    }
    catch (const HttpExceptionNotAllowed &e)
    {
        int code = e.getStatusCode();
        std::string methods = e.getAllowedMethods();
        logInfo("Acción: Método no permitido. Allowed: %s", methods.c_str());
        HttpResponse response(code);
        response.set_allow_methods(methods);
        response_str = response.getResponse();
        logInfo("response_str not allowed ok");
        _try_drain_and_adjust_response(client_socket, response_str);
    }
    catch (const HttpException &e)
    {
        int code = e.getStatusCode();
        logError("HTTP Exception caught: %s, code %d", e.what(), code);
        response_str = prepare_error_response(client_socket, code);
        logInfo("response_str error ok");
    }
    catch (const std::exception &e)
    {
        logError("Exception: %s", e.what());
        response_str = prepare_error_response(client_socket, HttpStatusCode::InternalServerError);
        logInfo("response_str error ok");
    }
    return response_str;
}

std::string ServerManager::prepare_error_response(int client_socket, int code)
{
    logInfo("Prep error: client socket %i. error %d", client_socket, code);
    std::string response_str;
    int server_fd = _get_client_server_fd(client_socket);
    if (server_fd == -1)
    {
        logError("prep error: client_socket %d not found in _client_server_map!", client_socket);
        HttpResponse response(HttpStatusCode::InternalServerError);
        return response.getResponse();
    }
    ServerUnit &server = _servers_map[server_fd];
    std::string err_page_path = server.getPathErrorPage(code);
    if (!err_page_path.empty())
    {
        HttpResponse response(code, WWW_ROOT + err_page_path);
        response_str = response.getResponse();
        return response_str;
    }
    std::string message = statusCodeString(code);
    switch (code)
    {
    case HttpStatusCode::NotFound:
    case HttpStatusCode::Forbidden:
    case HttpStatusCode::MethodNotAllowed:
    {
        HttpResponse response(code);
        response_str = response.getResponse();
    }
    break;
    case HttpStatusCode::InternalServerError:
        logError("Error. %s. Acción: Revisar los registros del servidor.", message.c_str());
        {
            HttpResponse response(code);
            response_str = response.getResponse();
        }
        break;
    case HttpStatusCode::BadRequest:
    {
        std::string body = "<h1>400 Bad Request</h1>";
        response_str =
            "HTTP/1.1 400 Bad Request\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: " +
            to_string(body.length()) + "\r\n"
                                       "Connection: close\r\n\r\n" +
            body;
    }
    break;
    default:
    {
        logError("Error no gestionado: %s. hacer algo!.", message.c_str());
        logError("🍊 Acción: Mostrar página de error %d.", code);
        HttpResponse response(code);
        response_str = response.getResponse();
    }
    break;
    }
    return response_str;
}

void ServerManager::_cleanup_client(int client_sock)
{
    FD_CLR(client_sock, &_read_fds);
    FD_CLR(client_sock, &_write_fds);
    close(client_sock);
    _client_server_map.erase(client_sock);
    _read_requests.erase(client_sock);
    _write_buffer.erase(client_sock);
    _bytes_sent.erase(client_sock);
    logInfo("Client socket %d cleaned up", client_sock);
}

void ServerManager::_handle_signal(int signal)
{
    (void)signal;
    ServerManager::_running = false;
}