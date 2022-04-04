#include <iostream>
#include <string>

using namespace std;

int main() {

    string input{};
    cout << "Enter a string to pyramid-ize: ";
    getline(cin, input);

    cout << endl; 

    size_t pad_size = input.length() - 1;
    string pad(pad_size, ' ');
    
    for (size_t i{0}; i < input.length(); i ++) {
        cout << '|' << pad;

        if (i != 0) {
            size_t tracker{};
            int direction{1};
            for (size_t j{0}; j<(i*2)+1; j++) {
                if (tracker == i) {
                    direction *= -1;
                }
                cout << input[tracker];
                tracker += direction;
            }
        } else
            cout << input.at(0);

        cout << pad << '|' << endl;
        pad.pop_back();
    }

    cout << endl;
    return 0;
}