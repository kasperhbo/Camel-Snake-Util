// Copyright 2019 Rica Radu Leonard
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

inline static std::string converCamelToSnake(std::string line) {
    for (auto it = line.begin() + 1; it < line.end(); ++it) {
        if (isupper(*it)) {
            *it = tolower(*it);
            if (islower(*(it - 1))) {
                it = line.insert(it, '_');
            }
        } else if (!isalpha(*(it - 1))) {
            if ((*it) == '_') {
                it = line.erase(it);
            }
        }
    }
    return line;
}
inline static std::string getNewFilename(const std::string& fileName, bool overwrite) {
    if (overwrite) {
        return fileName;
    }

    std::string new_name = std::string(fileName);
    new_name.insert(new_name.find_last_of("."), "_snaked");
    return new_name;
}
inline static void openFile(std::string &filename, const bool overwrite) {
    std::ifstream in_file(filename);
    std::ostringstream output_buffer;
    std::string line;
    while (std::getline(in_file, line)) {
        output_buffer << converCamelToSnake(line) << '\n';
    }
    in_file.close();
    std::ofstream out_file(getNewFilename(filename, overwrite));
    out_file << output_buffer.str();
}