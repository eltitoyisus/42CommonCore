# webserv

## Description

webserv is an HTTP server implementation project where you create your own web server in C++98, similar to NGINX. This project teaches you the internals of HTTP protocol and non-blocking I/O programming.

## Project Overview

Build an HTTP server capable of:
- Serving static websites
- Handling multiple simultaneous connections
- Processing GET, POST, and DELETE methods
- Managing CGI execution
- Supporting multiple ports and virtual hosts
- Handling file uploads
- Proper error handling and status codes

This project teaches you:
- HTTP/1.1 protocol implementation
- Non-blocking I/O with select/poll/epoll/kqueue
- Socket programming
- Configuration file parsing
- CGI execution
- Web server architecture
- C++ in a real-world application

## Mandatory Features

### HTTP Methods
- **GET** - Retrieve resources
- **POST** - Submit data (file uploads, forms)
- **DELETE** - Remove resources

### Server Capabilities
- Listen on multiple ports
- Multiple server configurations (virtual hosts)
- Default error pages
- Client body size limitation
- Route configuration with:
  - Accepted HTTP methods
  - HTTP redirections
  - Root directory
  - Directory listing
  - Default files
  - CGI execution
  - File upload directory

### Non-blocking I/O
- Handle multiple clients simultaneously
- Use `select()`, `poll()`, `epoll()`, or `kqueue()`
- Never block on read/write operations
- Proper timeout handling

### Configuration File
- NGINX-inspired configuration format
- Support multiple servers
- Customize error pages
- Set client body size limits
- Configure routes and locations

## Configuration File Format

**Example configuration:**
```nginx
server {
    listen 8080;
    server_name localhost;
    
    error_page 404 /errors/404.html;
    client_max_body_size 10M;
    
    location / {
        root /var/www/html;
        index index.html index.htm;
        autoindex on;
        allowed_methods GET POST;
    }
    
    location /upload {
        root /var/www/uploads;
        allowed_methods POST DELETE;
        client_max_body_size 50M;
    }
    
    location /cgi-bin {
        root /var/www/cgi-bin;
        cgi_extension .py .php;
        allowed_methods GET POST;
    }
}

server {
    listen 8081;
    server_name example.com;
    
    location / {
        root /var/www/example;
        index index.html;
    }
}
```

## Project Structure

```
webserv/
├── Makefile
├── README.md
├── config/
│   └── default.conf        # Configuration files
├── includes/
│   ├── Server.hpp
│   ├── Client.hpp
│   ├── Request.hpp
│   ├── Response.hpp
│   ├── Config.hpp
│   └── webserv.hpp
├── src/
│   ├── main.cpp
│   ├── Server.cpp
│   ├── Client.cpp
│   ├── Request.cpp
│   ├── Response.cpp
│   ├── Config.cpp
│   ├── Parser.cpp
│   └── CGI.cpp
├── www/                    # Web root
│   ├── index.html
│   ├── errors/
│   └── uploads/
└── cgi-bin/               # CGI scripts
    ├── test.py
    └── test.php
```

## Key Components

### 1. Configuration Parser
Parse NGINX-style configuration files:
- Server blocks
- Listen directives
- Location blocks
- Error pages
- Client settings

### 2. HTTP Request Parser
Parse HTTP requests:
```
GET /index.html HTTP/1.1
Host: localhost:8080
User-Agent: Mozilla/5.0
Accept: text/html
```

Components:
- Request line (method, URI, version)
- Headers
- Body (for POST)

### 3. HTTP Response Generator
Generate HTTP responses:
```
HTTP/1.1 200 OK
Content-Type: text/html
Content-Length: 1234

<html>...</html>
```

Status codes to handle:
- 200 OK
- 201 Created
- 204 No Content
- 301 Moved Permanently
- 400 Bad Request
- 403 Forbidden
- 404 Not Found
- 405 Method Not Allowed
- 413 Payload Too Large
- 500 Internal Server Error
- 501 Not Implemented
- 505 HTTP Version Not Supported

### 4. Non-blocking I/O Manager
Use one of:
- `select()` - Portable, limited to 1024 FDs
- `poll()` - Better than select, no FD limit
- `epoll()` - Linux, high performance
- `kqueue()` - BSD/macOS, high performance

### 5. CGI Handler
Execute CGI scripts:
- Set environment variables (QUERY_STRING, REQUEST_METHOD, etc.)
- Fork and execute script
- Pipe input/output
- Handle script timeouts

## CGI Environment Variables

```
REQUEST_METHOD=GET
QUERY_STRING=name=value&other=data
CONTENT_TYPE=application/x-www-form-urlencoded
CONTENT_LENGTH=42
SCRIPT_NAME=/cgi-bin/script.py
PATH_INFO=/extra/path
SERVER_PROTOCOL=HTTP/1.1
GATEWAY_INTERFACE=CGI/1.1
```

## Usage

```bash
# Compile
make

# Run with default config
./webserv

# Run with custom config
./webserv config/custom.conf
```

## Testing

### Manual Testing
```bash
# Using curl
curl http://localhost:8080/
curl -X POST -d "data=value" http://localhost:8080/form
curl -X DELETE http://localhost:8080/file.txt

# Using browser
open http://localhost:8080
```

### Stress Testing
```bash
# Using siege
siege -c 100 -t 30s http://localhost:8080/

# Using ab (Apache Bench)
ab -n 1000 -c 10 http://localhost:8080/
```

### Testing Tools Included
- `siege_stress_test.sh` - Stress testing script
- `port_tests.sh` - Port configuration testing
- `my_tester.sh` - Custom test suite
- `setup_tester_files.sh` - Test environment setup
- `cgi_tester` - CGI functionality tests

## Common Challenges

### 1. Non-blocking I/O
- Handling partial reads/writes
- Managing connection states
- Proper timeout handling

### 2. HTTP Parsing
- Chunked transfer encoding
- Multipart form data
- Malformed requests

### 3. CGI Execution
- Setting up environment correctly
- Handling script failures
- Preventing CGI hanging

### 4. Memory Management
- Preventing leaks
- Managing multiple connections
- Buffer management

### 5. Concurrency
- Race conditions
- Proper FD management
- Connection cleanup

## HTTP Request Examples

### GET Request
```http
GET /index.html HTTP/1.1
Host: localhost:8080
Connection: keep-alive
```

### POST Request (Form)
```http
POST /submit HTTP/1.1
Host: localhost:8080
Content-Type: application/x-www-form-urlencoded
Content-Length: 27

name=John&message=Hello
```

### POST Request (File Upload)
```http
POST /upload HTTP/1.1
Host: localhost:8080
Content-Type: multipart/form-data; boundary=----Boundary
Content-Length: 1234

------Boundary
Content-Disposition: form-data; name="file"; filename="test.txt"
Content-Type: text/plain

[file contents]
------Boundary--
```

### DELETE Request
```http
DELETE /files/document.txt HTTP/1.1
Host: localhost:8080
```

## Debugging Tips

```bash
# Check open connections
netstat -an | grep 8080

# Monitor file descriptors
lsof -p <pid>

# Test with telnet
telnet localhost 8080
GET / HTTP/1.1
Host: localhost

# Use browser DevTools
# Network tab shows requests/responses
```

## Performance Considerations

- Use efficient data structures
- Minimize memory allocations
- Proper buffer sizing
- Connection pooling
- Keep-alive support
- Efficient file I/O

## Allowed Functions

- I/O: `read`, `write`, `close`, `open`
- Sockets: `socket`, `bind`, `listen`, `accept`, `connect`, `send`, `recv`
- Multiplexing: `select`, `poll`, `epoll_*`, `kqueue`
- Process: `fork`, `execve`, `wait`, `waitpid`, `kill`
- File: `stat`, `lstat`, `fstat`, `access`, `opendir`, `readdir`, `closedir`
- Signals: `signal`, `sigaction`
- Network: `getsockname`, `getprotobyname`, `gethostbyname`, `getaddrinfo`, `freeaddrinfo`, `setsockopt`
- Misc: `fcntl`, `strerror`, `errno`

## Skills Acquired

- HTTP protocol deep understanding
- Non-blocking I/O programming
- Socket programming
- Multiplexing (select/poll/epoll/kqueue)
- Configuration file parsing
- CGI protocol implementation
- Web server architecture
- Concurrent programming
- C++ in real-world applications
- Network protocol implementation
- Performance optimization
- Error handling at scale

## Circle

**Circle 5** - Advanced network programming project at 42 School
