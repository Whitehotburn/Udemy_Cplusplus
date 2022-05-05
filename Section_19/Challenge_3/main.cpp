// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    std::ifstream in_file;
    in_file.open("./romeoandjuliet.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    std::string in_word;
    std::string desired_word{};
    int case_sensitive{};

    std::cout << "\nEnter the substring to search for: ";
    cin >> desired_word;

    std::cout << "\nCase sensitive? Press 1 for yes, 0 for no: ";
    cin >> case_sensitive;
    
    if (!case_sensitive)
        transform(desired_word.begin(), desired_word.end(), desired_word.begin(), ::tolower);

    size_t desired_word_count{};
    size_t total_word_count{};
    
    while (in_file >> in_word) {
        if (!case_sensitive)
            transform(in_word.begin(), in_word.end(), in_word.begin(), ::tolower);

        size_t found = in_word.find(desired_word);

        if (found!=std::string::npos)
            desired_word_count++;
        total_word_count++;
    }

    std::cout << total_word_count << " words were searched..." << std::endl;
    std::cout << "The substring \"" << desired_word << "\" was found " << desired_word_count << " times." << std::endl;

    in_file.close();
    cout << endl;
    return 0;
}

