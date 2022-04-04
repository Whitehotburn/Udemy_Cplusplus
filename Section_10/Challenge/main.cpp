#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string alphabet{"abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASR xznlwebgjhqdyvtkfuompciasr"};

    string input{};
    cout << "Enter a string to encrypt and decrypt: ";
    getline(cin, input);
    
    string encode{};

    for (size_t i{0}; i < input.length(); i++) {
        if (isalpha(input.at(i))) // only handle letters
            encode.push_back(key.at(alphabet.find(input.at(i))));
        else
            encode.push_back(input.at(i));
    }

    cout << "The encoded message is: ";
    cout << encode << endl;

    string decode{};

    for (size_t i{0}; i < encode.length(); i++) {
        if (isalpha(input.at(i))) // only handle letters
            decode.push_back(alphabet.at(key.find(encode.at(i))));
        else
            decode.push_back(input.at(i));
    }

    cout << "The decoded message is: ";
    cout << decode << endl;

    return 0;
}