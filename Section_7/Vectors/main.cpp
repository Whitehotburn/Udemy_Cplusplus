// Section 7 - Vectors

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector <char> vowels {'a', 'e', 'i', 'o', 'u'};

    cout << vowels[0] << endl;
    cout << vowels[4] << endl;

    vector <int> test_scores {100, 98, 89};

    cout << "\nTest scores using array syntax:" << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;

    cout << "\nTest scores using vector syntax:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "\nThere are " << test_scores.size() << " scores in the vector" << endl;

    cout << "\nEnter 3 test scores: " << endl;
    cin >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);

    cout << "\nUpdated test scores: " << endl;

    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;

    cout << "\nEnter a test score to add to the vector: ";
    int score_to_add {0};
    cin >> score_to_add;

    test_scores.push_back(score_to_add);

    cout << "\nEnter one more test score to add to the vector: ";
    cin >> score_to_add;
    test_scores.push_back(score_to_add);

    cout << "\nTest scores are now: " << endl;

    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << test_scores.at(4) << endl;

    cout << "\nThere are now " << test_scores.size() << " scores in the vector" << endl;

    return 0;
}