#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(int); // be careful with default arguments
void print(double);
void print(string);
void print(string, string);
void print (vector<string>);

void print(int num) {
    cout << "Printing int: " << num << endl;
}

void print(double num) {
    cout << "Printing double: " << num << endl;
}

void print(string s) {
    cout << "Printing string: " << s << endl;
}

void print(string s, string t) {
    cout << "Printing 2 strings: " << s << " and " << t << endl;
}

void print(vector<string> v) {
    cout << "Printing vector of strings: ";
    for (auto s: v)
        cout << s + " ";
    cout << endl;
}


int main() {

    print(100); // int
    print('A'); // char always promoted to int (65)

    print(123.5); // double
    print(123.3F); // float promoted to double

    print("C-style string"); // C-style string converted to C++ string

    string s {"C++ string"};
    print (s); // C++ string

    print("C-style string", s); // first arg is converted to C++ style string

    vector<string> three_stooges {"Larry", "Moe", "Curly"};
    print(three_stooges);

    cout << endl;
    return 0;
}