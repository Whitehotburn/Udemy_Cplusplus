// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream in_file {"./romeoandjuliet.txt"};
    std::ofstream out_file{"./Challenge_4_solution.txt"};
    if (!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }
     if (!out_file) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    size_t line_number{};
    std::string line{};

    while (std::getline(in_file, line)) {
        line_number++;
        if (line != "\r" && line != "") { // account for both windows & unix line termination
            out_file << std::setw(6) << std::left << line_number;
        }
        out_file << std::left << line << std::endl;

    }
    
    std::cout << "File copied" << std::endl;
    in_file.close();
    out_file.close();
    return 0;
}
