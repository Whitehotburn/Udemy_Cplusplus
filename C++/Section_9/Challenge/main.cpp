#include <iostream>
#include <vector>

using namespace std;

int main() {

    char selection{};
    vector<int> vec{};
    cout << "\nWelcome to the section 9 challenge!" << endl;

    do {

        cout << "\n--------------------------" << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> selection;

        switch (selection) {
            case 'p':
            case 'P':
                if (vec.empty()) {
                    cout << "[] - the list is empty" << endl;
                } else {
                    cout << "[";
                    for (auto num: vec)
                        cout << " " << num << " ";
                    cout << "]" << endl;
                }
                break;

            case 'a':
            case 'A':
            {
                cout << "Enter an integer to add to the list: ";
                int num{};
                cin >> num;
                vec.push_back(num);
                cout << num << " added" << endl;
            }
                break;

            case 'c':
            case 'C':
            {
                cout << "Clearing the vector..." << endl;
                vec.clear();
            }
                break;

            case 'm':
            case 'M':
            {
                if (vec.empty()) {
                    cout << "Unable to calculate the mean - no data" << endl;
                } else {
                    int avg{};
                    cout << "The average of the list is: ";
                    for (auto num: vec)
                        avg += num;
                    avg /= vec.size();
                    cout << avg << endl;
                }
            }
                break;

            case 's':
            case 'S':
            {
                if (vec.empty()) {
                    cout << "Unable to determine the smallest number - list is empty." << endl;
                } else {
                    int small{};
                    small = *min_element(vec.begin(), vec.end());
                    cout << "The smallest number is: " << small << endl;
                }
            }
                break;

            case 'l':
            case 'L':
            {
                if (vec.empty()) {
                    cout << "Unable to determine the largest number - list is empty." << endl;
                } else {
                    int small{};
                    small = *max_element(vec.begin(), vec.end());
                    cout << "The largest number is: " << small << endl;
                }
            }
                break;

            case 'f':
            case 'F':
            {
                int seek{};
                int count{};
                cout << "Enter the number you would like to know the count of: ";
                cin >> seek;
                for (auto val: vec)
                    if (val == seek)
                        count += 1;
                cout << seek << " appears in the list " << count << " times." << endl;
            }
                break;
            default:
            cout << "Sorry, that's not a valid input, please try again..." << endl;
        }

    } while (selection != 'q' && selection != 'Q');


    cout << "\nGoodbye." << endl;
    return 0;
}
