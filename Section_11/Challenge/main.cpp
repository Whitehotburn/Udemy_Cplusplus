#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototypes

void ensure_uppercase(char&);
void print_menu();
void print_list(const vector<int>&);
void add_number(vector<int>&);
void average(const vector<int>&);
void smallest(const vector<int>&);
void largest(const vector<int>&);
void find(const vector<int>&,size_t);
void clear_list(vector<int>&);

// Function definitions

void print_menu(){
    cout << "\n--------------------------" << endl;
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display average of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Display the count of a certain value in the list" << endl;
    cout << "C - Clear the list" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

void ensure_uppercase(char &selection){
    cin >> selection;
    if (isalpha(selection) && not isupper(selection))
        selection = toupper(selection);
}

void print_list(const vector<int> &vec){
    if (vec.empty()) {
        cout << "[] - the list is empty" << endl;
    } else {
        cout << "[";
        for (auto num: vec)
            cout << " " << num << " ";
        cout << "]" << endl;
    }
}

void add_number(vector<int> &vec){
    cout << "Enter an integer to add to the list: ";
    int num{};
    cin >> num;
    vec.push_back(num);
    cout << num << " added" << endl;
}

void average(const vector<int> &vec){
    if (vec.empty()) {
        cout << "Unable to calculate the average - no data" << endl;
    } else {
        double avg{};
        cout << "The average of the list is: ";
        for (auto num: vec)
            avg += num;
        avg /= vec.size();
        cout << avg << endl;
    }
}

void smallest(const vector<int> &vec){
    if (vec.empty()) {
        cout << "Unable to determine the smallest number - list is empty." << endl;
    } else {
        int small{};
        small = *min_element(vec.begin(), vec.end());
        cout << "The smallest number is: " << small << endl;
    }
}

void largest(const vector<int> &vec){
    if (vec.empty()) {
        cout << "Unable to determine the largest number - list is empty." << endl;
    } else {
        int large{};
        large = *max_element(vec.begin(), vec.end());
        cout << "The largest number is: " << large << endl;
    }
}

void find(const vector<int> &vec, int seek){
    size_t count{};
    for (auto val: vec)
        if (val == seek)
            count += 1;
    cout << seek << " appears in the list " << count << " times." << endl;
}

void clear_list(vector<int> &vec){
    cout << "Clearing the vector..." << endl;
    vec.clear();
}

int main() {

    char selection{};
    vector<int> vec{};
    cout << "\nWelcome to the section 11 (improved section 9) challenge!" << endl;

    do {
        selection = {};
        print_menu();
        ensure_uppercase(selection);

        if (selection == 'P') {
            print_list(vec);

        } else if (selection == 'A') {
            add_number(vec);

        } else if (selection == 'M') {
            average(vec);

        } else if (selection == 'S') {
            smallest(vec);

        } else if (selection == 'L') {
            largest(vec);

        } else if (selection == 'Q') {
            cout << "Goodbye." << endl;

        } else if (selection == 'F') {
            int seek{};
            cout << "Enter the number you would like to know the count of in the list: ";
            cin >> seek;
            find(vec, seek);

        } else if (selection == 'C') {
            clear_list(vec);

        } else {
            cout << "Sorry, that's not a valid input, please try again..." << endl;
        }

    } while (selection != 'Q');

    cout << endl;
    return 0;
}
