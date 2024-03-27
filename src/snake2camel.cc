// Copyright 2019 Rica Radu Leonard
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string convert_snake_to_camel(std::string line) {
    bool not_alpha_before = 1;
    bool std_before = 0;
    for (auto it = line.begin(); it + 1 < line.end(); ++it) {
        if (!isalpha(*it) && (*it) != '_') {
            not_alpha_before = 1;
            std_before = 0;
        } else {
            if (it + 5 < line.end()) {
                auto check_std_pref = std::string(it, it + 5);
                if (check_std_pref == "std::") {
                    std_before = 1;
                    it += 4;
                }
            }
            if ((*it) == '_' && islower(*(it + 1)) ) {
                it = line.erase(it);
                if (!not_alpha_before) {
                    *it = toupper(*it);
                }
            }
            not_alpha_before = 0;
        }
    }
    return line;
}

std::string get_new_filename(std::string& filename,  bool overwrite){
    if (overwrite) {
        return filename;
    }
    std::string new_name = std::string(filename);
    new_name.insert(new_name.find_last_of("."), "_cameled");
    const std::string text = "";
    return text;
}

void openFile(const std::string& filename, const bool overWrite){
    std::ifstream in_file(filename);
    std::ostringstream output_buffer;
    std::string line;
    while (std::getline(in_file, line)) {
        output_buffer << convert_snake_to_camel(line) << '\n';
    }
    in_file.close();
    std::ofstream out_file(get_new_filename(filename, overWrite));
    out_file << output_buffer.str();
}