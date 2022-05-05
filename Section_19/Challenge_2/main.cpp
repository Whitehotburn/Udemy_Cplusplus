// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <string>

// Function prototypes
void print_header(const int &, const int &, const int &);
void print_footer(const int &, const int &, const int &, const double &average);
void print_student(const int &, const int &, const int &, const std::string &student, const int &score);
int process_response(const std::string &response, const std::string &answer_key);

void print_header(const int &total_width, const int &field_1_width, const int &field_2_width) {
    std::string underline(total_width, '-');
    std::cout << "\n" << underline << std::endl;
    std::cout << std::setw(field_1_width) << std::left << "Student"
              << std::setw(field_2_width + 1) << std::right << "Score" << std::endl;
    std::cout << underline << std::endl;
}

void print_footer(const int &total_width, const int &field_1_width, const int &field_2_width, const double &average) {
    std::string underline(total_width, '-');
    std::cout << underline << std::endl;
    std::cout << std::setw(field_1_width) << std::left << "Average score" << "|"
              << std::setw(field_2_width) << std::right << std::setprecision(1) << std::fixed
              << average << std::endl;
    std::cout << underline << "\n" << std::endl;
}

void print_student(const int &total_width, const int &field_1_width, const int &field_2_width, const std::string &student, const int &score) {
    std::cout << std::setw(field_1_width) << std::left << student << "|"
              << std::setw(field_2_width) << std::right << score << std::endl;
}

int process_response(const std::string &response, const std::string &ans_key) {
    int score{};
    for (size_t i = 0; i < ans_key.size(); i++) {
        if (response.at(i) == ans_key.at(i))
        score++;
    }
    return score;
}

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
    int cum_score{};
    int num_of_students{};
    double average{};

    print_header(total_width, field_1_width, field_2_width);

    std::string ans_key{};
    std::string name{};
    std::string response{};

    in_file >> ans_key;

    while (in_file >> name >> response) {
        ++num_of_students;
        int score = process_response(response, ans_key);
        cum_score += score;
        print_student(total_width, field_1_width, field_2_width, name, score);
    }

    if (num_of_students != 0)
        average = static_cast<double>(cum_score)/num_of_students;

    print_footer(total_width, field_1_width, field_2_width, average);

    in_file.close();
    return 0;
}