#include "utils.h"

bool match_filename(const std::string &filename, const std::string &query) {
    return filename.find(query) != std::string::npos;
}

bool has_extension(const std::string &filename, const std::string &extension) {
    if (extension.empty()) return true;
    return filename.size() >= extension.size() &&
        filename.substr(filename.size() - extension.size()) == extension;
}
