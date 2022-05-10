// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.

    std::stack<char> string_stack {};
    std::queue<char> string_queue {};

    for (auto c: s) {
        if (std::isalpha(c)) {
            string_stack.push(std::toupper(c));
            string_queue.push(std::toupper(c));
        }
    }

    char stack_temp {};
    char queue_temp {};
    
    while (!string_queue.empty()) { // or !string_stack.empty()
        stack_temp = string_stack.top();
        queue_temp = string_queue.front();

        if (stack_temp != queue_temp)
            return false;
        
        string_stack.pop();
        string_queue.pop();
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
        std::cout << std::setw(8) << std::left << (is_palindrome(s) ? "True" : "False")  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}