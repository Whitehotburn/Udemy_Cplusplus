#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string alphabet{" ^'_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"^ _'XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    string input{};
    cout << "Enter a string to encrypt and decrypt: ";
    getline(cin, input);
    
    string encode{};

    for (char c: input) {
        size_t position = alphabet.find(c);
        if (position != string::npos) { // only handle defined alphabet
            encode.push_back(key.at(position));
        } else {
            encode.push_back(c);
        }
    }

    cout << "The encoded message is: ";
    cout << encode << endl;

    string decode{};

    for (char c: encode) {
        size_t position = key.find(c);
        if (position != string::npos) { // only handle defined alphabet
            decode.push_back(alphabet.at(position));
        } else {
            decode.push_back(c);
        }
    }

    cout << "The decoded message is: ";
    cout << decode << endl;

    return 0;
}