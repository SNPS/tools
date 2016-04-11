#ifndef EX_COMMON_HPP
#define EX_COMMON_HPP

#include <fstream>
#include <string>

namespace ex {
    /* Determine file data length. */
    std::ifstream::pos_type get_file_length(const std::string& file_name);
}

#endif
