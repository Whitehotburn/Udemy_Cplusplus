#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vec {14, 26, 85, 100};

    int count{};
    int length = vec.size();

    while (count < length && vec.at(count) != -99 )
        count++;

    cout << count << endl;
    return count;

}
