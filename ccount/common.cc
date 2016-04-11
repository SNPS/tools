#include "common.hpp"

#include <fstream>
#include <string>

namespace ex {
    /* Determine file data length. */
    std::ifstream::pos_type get_file_length(const std::string& file_name) {
        std::ifstream appFile{file_name, std::ios::ate};
        return appFile.tellg() / 370;
    }
}
