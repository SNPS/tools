#include "common.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

static constexpr const char DELIM = ',';

namespace read {
    class line {
        std::string data;
    public:
        friend std::istream& operator>>(std::istream& is, line& l) {
            std::getline(is, l.data);
            return is;
        }
        operator std::string() const { return data; }
    };
}

int main(int argc, char* argv[]) {
    // ษออออออออออออออออออออออออออออออออป
    // บ Check program input arguments. บ
    // ศออออออออออออออออออออออออออออออออผ
    if (argc != 2) {
        std::cout << "Usage: CCOUNT <input file>" << std::endl;
        return EXIT_FAILURE;
    }

    // ษอออออออออออออออออออออออป
    // บ Estimate file length. บ
    // ศอออออออออออออออออออออออผ
    auto file_len = ex::get_file_length(argv[1]);

    // ษอออออออออออออออออออออออออออออออป
    // บ Read all instances from file. บ
    // ศอออออออออออออออออออออออออออออออผ
    std::cout << "Checking row structure in file..." << std::endl;

    std::ifstream file{argv[1]};

    auto it = std::istream_iterator<read::line>{file};
    std::string line = *it++;
    auto nbr_columns = std::count(std::begin(line), std::end(line), DELIM);

    std::size_t line_count = 2;
    std::vector<std::size_t> faulty_line_indices;

    auto nbr_faulty_columns = std::accumulate(it, std::istream_iterator<read::line>{}, 0,
        [&] (int mem, const std::string& line) {
            auto cols = std::count(std::begin(line), std::end(line), DELIM);
            if (cols != nbr_columns) {
                faulty_line_indices.push_back(line_count);
                mem += 1;
            }

            // Output progress.
            if (++line_count % 100 == 0) {
                std::cout << "\r" << line_count * 100 / file_len << " %";
            }

            return mem;
        }
    );
    std::cout << "\r100 %" << std::endl;

    std::cout << "Column count should be: " << nbr_columns + 1 << std::endl;
    std::cout << "Number of faulty columns: " << nbr_faulty_columns << std::endl;

    if (!faulty_line_indices.empty()) {
        std::cout << "Faults occur at lines:" << std::endl;
        for (auto&& line_index : faulty_line_indices) {
            std::cout << line_index << std::endl;
        }
    }
}
