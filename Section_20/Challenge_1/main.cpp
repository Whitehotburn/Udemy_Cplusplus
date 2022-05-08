// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.

    std::deque<char> in_string {};

    for (auto c: s) {
        if (std::isalpha(c)) {
            in_string.push_back(std::toupper(c));
        }
    }

    char c1{};
    char c2{};

    while (in_string.size() > 1) {
        c1 = in_string.front();
        c2 = in_string.back();
        in_string.pop_front();
        in_string.pop_back();

        if (c1 != c2)
            return false;
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(10) << std::left << (is_palindrome(s) ? "True" : "False") << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
