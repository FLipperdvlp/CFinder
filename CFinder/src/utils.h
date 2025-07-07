#ifndef UTILS_H
#define UTILS_H

#include <string>

bool match_filename(const std::string &filename, const std::string &query);
bool has_extension(const std::string &filename, const std::string &extension);

#endif
