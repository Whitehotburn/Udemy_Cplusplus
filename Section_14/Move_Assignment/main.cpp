#include <iostream>
#include <vector>
#include "Mystring.h"

int main() {
    Mystring a{"Hello"};
    a = Mystring{"Hola"};
    a = "Bonjour";

    return 0;
}