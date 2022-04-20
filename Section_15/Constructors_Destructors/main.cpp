#include <iostream>

class Base {
private:
    int value;
public:
    Base() : value{0} {std::cout << "Base no-args constructor" << std::endl;}
    Base(int x) : value{x} {std::cout << "Base (int) overloaded constructor" << std::endl;}
    ~Base() {std::cout << "Base destuctor" << std::endl;}
};

class Derived : public Base {
    using Base::Base; // inherit non-special constructors from base class
private:
    int doubled_value;
public:
Derived() : doubled_value {0} {std::cout << "Derived no-args constructor" << std::endl;}
Derived(int x) : doubled_value {x*2} {std::cout << "Derived (int) overloaded constructor" << std::endl;}
~Derived() {std::cout << "Derived destructor" << std::endl;}
};

int main() {
    // Base b;      // calls line 7 no-args constructor
    // Base b{100}; // calls line 8 int arg constructor

    // Derived d;      // calls line 16, then 7, base class constructor executes first
    Derived d {1000};  // calls base class no-args constructor, learn how to do this soon



    return 0;
}