#include <iostream>
#include <filesystem>
#include <string>
#include "search.h"
#include "utils.h"

namespace fs = std::filesystem;

extern "C" void search_directory(const char *base_path, const char *query, const char *extension) {
    try {
        fs::recursive_directory_iterator it(base_path, fs::directory_options::skip_permission_denied);
        std::cout << std::endl << "Searching results: " << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "|" << std::endl;
        for (const auto& entry : it) {
            if (entry.is_regular_file()) {
            std::string filename = entry.path().filename().string();
            std::string path = entry.path().string();
                if (match_filename(filename, query)) {
                    if (!extension || has_extension(filename, extension)) {
                        std::cout << "|     " << path << std::endl;
                    }
                }
            }
        }
        std::cout << "|" << std::endl << "---------------------------------------------------" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error during search: " << e.what() << std::endl;
    }
}
