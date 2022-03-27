// Section 7 challenge

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // Declare 2 empty vectors of ints

    vector <int> vector1;
    vector <int> vector2;

    // Add 10 and 20 to vector 1 using push_back

    vector1.push_back(10);
    vector1.push_back(20);

    // Display the elements of vector 1 using the .at() method and size using .size()

    cout << "Vector 1 contains:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "Vector 1 has a size of: " << vector1.size() << endl;

    // Add 100 and 200 to vector 2 using push_back

    vector2.push_back(100);
    vector2.push_back(200);

    // Display the elements of vector 1 using the .at() method and size using .size()

    cout << "\nVector 2 contains:" << endl;
    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    cout << "Vector 2 has a size of: " << vector2.size() << endl;

    // Declare an empty 2D vector called vector_2d
    // vector_2d is a vector of vector<int>

    vector <vector<int>> vector_2d;

    // Add vector 1 and vector 2 to vector_2d using push_back

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    // Display the elements of vector_2d using the .at() method

    cout << "\nVector 2d is a vector of vectors:" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    // Change vector1.at() to 1000

    vector1.at(0) = 1000;

    // Display the elements in vector_2d again using the .at() method

    cout << "\nVector 2d has changed to:" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    // Display the elements in vector 1 again to verify change

    cout << "\nVector 1 is now:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;

    return 0;
}
