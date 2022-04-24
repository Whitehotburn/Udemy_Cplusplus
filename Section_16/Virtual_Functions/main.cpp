// Section 16
// Using Base class pointers

#include <iostream>
#include <vector>

// dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    // virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) { // virtual optional here - better for readability
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    // virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) { // virtual optional here - better for readability
        std::cout << "In Savings::withdraw" << std::endl;
    }
    // virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) { // virtual optional here - better for readability
        std::cout << "In Trust::withdraw" << std::endl;
    }
    // virtual ~Trust() {  }
};

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
        
    return 0;
}

