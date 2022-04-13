#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<string> *const v) {
    for (auto str: *v)
        cout << str << " ";
    cout << endl;
    // v = nullptr; can't do this, *const
}


void display(int *array, int sentinel) {
    while (*array != sentinel)
        cout << *array++ << " ";
    cout << endl;

}

int main() {

    vector<string> stooges {"Larry", "Moe", "Curly"};
    display(&stooges);

    cout << "\n----------------" << endl;
    int scores[] {100, 98, 97, 79, 85, -1};
    display(scores, -1);

    cout << endl;
    return 0;
}