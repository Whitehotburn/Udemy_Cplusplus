# include <iostream>

using namespace std;

void print(const int *const array, const size_t &size) {
    cout << "[ ";
    for (size_t i{0}; i<size; i++)
        cout << array[i] << " ";
    cout << "]" << endl;
}

int *apply_all(const int *const &array_1, const size_t &size_1, const int *const &array_2, const size_t &size_2) {
    int *new_array{nullptr};
    new_array = new int[size_1 * size_2];
    size_t count{};

    for (size_t i{0}; i<size_2; i++){
        for (size_t j{0}; j<size_1; j++){
            // *(new_array + count) = array_2[i] * array_1[j];
            new_array[count] = array_2[i] * array_1[j];
            count++;
        }
    }
    return new_array;
}

int main() {
    const size_t array1_size{5};
    const size_t array2_size{3};

    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};

    cout << "Array 1: ";
    print(array1, array1_size);

    cout << "Array 2: ";
    print(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: ";
    print(results, results_size);

    delete [] results;
    cout << endl;
    return 0;
}