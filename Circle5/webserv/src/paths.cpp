#include "../include/WebServ.hpp"

std::string clean_path(const std::string& path) {
	std::string cleaned = path;
	cleaned = replace_all(cleaned, "%20", " ");
	return cleaned;
}

std::string path_normalization(const std::string& path) {
	std::string normalized = path;
	size_t pos;
	while ((pos = normalized.find("//")) != std::string::npos) {
		normalized.replace(pos, 2, "/");
	}
	while ((pos = normalized.find("/./")) != std::string::npos) {
		normalized.replace(pos, 3, "/");
	}
	while ((pos = normalized.find("/../")) != std::string::npos) {
		if (pos == 0) {
			normalized.erase(0, 3);
		} else {
			size_t prev_slash = normalized.rfind('/', pos - 1);
			if (prev_slash == std::string::npos) {
				normalized.erase(0, pos + 4);
			} else {
				normalized.erase(prev_slash, pos + 3 - prev_slash);
			}
		}
	}
	return normalized;
}
