#include <iostream>
#include "Mystring.h"

int main() {
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    Mystring curly;

    std::cout << "Enter the third stooge's first name: ";
    std::cin >> curly;

    std::cout << "The three stooges are " << larry << ", " << moe << ", " << curly << std::endl;

    std::cout << "\nEnter the three stooges names separated by a space: ";
    std::cin >> larry >> moe >> curly;

    std::cout << "The three stooges are " << larry << ", " << moe << ", " << curly << std::endl;

    return 0;
}