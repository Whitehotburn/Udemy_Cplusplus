#include <iostream>

using namespace std;
unsigned long long fibonacci(unsigned long long);
unsigned long long factorial(unsigned long long);

unsigned long long fibonacci(unsigned long long n) {
    if (n <= 1)
        return n;	             // base cases
    return fibonacci(n-1) + fibonacci(n-2); // recursion
}

unsigned long long factorial(unsigned long long n) {
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

int main() {
    cout << "Fibonacci of 5: " << fibonacci(5) << endl;   // 5
    cout << "Fibonacci of 30: " << fibonacci(30) << endl;	// 832040 
    cout << "Fibonacci of 40: " << fibonacci(40) << endl; // 102334155

    cout << "\nFactorial of 1: " << factorial(1) << endl;
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Factorial of 10: " << factorial(10) << endl;
    return 0;
}
