#include <iostream>
#include <vector>
using namespace std;

int main() {
    //----WRITE YOUR CODE BELOW THIS LINE----
    vector<int> vec{1, 2, 3};

    if (vec.empty() || vec.size() == 1)
        return 0;

    int result{};
    int length = vec.size();

    for (int i{0}; i<length; i++) {
        for (int j{i+1}; j<length; j++) {
            result += vec.at(i) * vec.at(j);
        }   
    }
     
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    cout << result << endl;
    return result;
}