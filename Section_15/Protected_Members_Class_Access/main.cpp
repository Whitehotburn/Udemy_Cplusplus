#include <iostream>

class Base {
    // Note: friends of base have access to all
public:
    int a{0};
    void display() {std::cout << a << ", " << b << ", " << c << std::endl;}
protected:
    int b{0};
private:
    int c{0};
};

class Derived: public Base {
    // Note: friends of Derived have access to only what Derived has access to

    // a will be public
    // b will be protected
    // c will not be accessible
public:
    void access_base_members() {
        a = 100; // OK
        b = 200; // OK
        // c = 300; // compiler error, access through getter
    }
};

int main() {

    std::cout << "=== Base number access from base objects ==========" << std::endl;
    Base base;
    base.a = 100; // OK
    // base.b = 200; // compiler error
    // base.c = 300; // compiler error, access through getter


    std::cout << "=== Base number access from derived objects =======" << std::endl;
    Derived d;
    d.a = 100; // OK
    // d.b = 200; // compiler error
    // d.c = 300; // compiler error

    return 0;
}