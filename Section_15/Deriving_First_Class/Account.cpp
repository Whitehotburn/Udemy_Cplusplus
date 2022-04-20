#include <iostream>
#include "Account.h"

Account::Account() 
    : balance{0}, name{"An Account"} {
}

Account::~Account()
{
}

void Account::deposit(double amount) {
std::cout << "Account deposit called with $" << amount << std::endl;
balance += amount;
}

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with $" << amount << std::endl;
balance -= amount;
}

void Account::display_balance() {
    std::cout << "Your balance is now: $" << balance << std::endl;
}