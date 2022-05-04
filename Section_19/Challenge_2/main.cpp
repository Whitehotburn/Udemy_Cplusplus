// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream in_file;
    in_file.open("./responses.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    const int total_width = 35;
    const int field_1_width = 29;
    const int field_2_width = 5;
    double cum_score{};
    int num_of_scores{};

    std::string underline(total_width, '-');

    size_t count = 0;
    std::string ans_key{};
    std::string line{};
    while (std::getline(in_file, line)) {
        if (count == 0) {
            ans_key = line.erase(line.size() - 1);
            std::cout << "\n" << std::setw(field_1_width) << std::left << "Student"
                      << std::setw(field_2_width + 1) << std::right << "Score" << std::endl;
            std::cout << underline << std::endl;
            count++;
            continue;
        }
        
        // Odd lines are the student names
        if (count % 2 != 0) {
            line.erase(line.size() - 1);
            std::cout << std::setw(field_1_width) << std::left << line << "|";
        }
        // Even lines are the students' scores
        else if (count % 2 == 0 && count != 0) {
            size_t score = 0;
            for (size_t i{0}; i < ans_key.size(); i++) {
                if (line[i] == ans_key[i])
                    score += 1;
            }
            cum_score += score;
            num_of_scores += 1;
            std::cout << std::setw(field_2_width) << std::right << score << std::endl;
        }
        count ++;
    }
    in_file.close();

    std::cout << underline << std::endl;
    std::cout << std::setw(field_1_width) << std::left << "Average score" << "|"
              << std::setw(field_2_width) << std::right << std::setprecision(1) << std::fixed
              << cum_score/num_of_scores << std::endl;
    std::cout << underline << "\n" << std::endl;


    return 0;
}