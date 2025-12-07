#ifndef PATHS_HPP
#define PATHS_HPP

#include <string>

const std::string WWW_ROOT = "www/";
const std::string DEFAULT_INDEX = WWW_ROOT + "index.html";

const std::string CGI_BIN = "cgi-bin/";
const std::string UPLOADS_URI = "www//upload";

std::string		clean_path(const std::string& path);
std::string		path_normalization(const std::string& path);
#endif
