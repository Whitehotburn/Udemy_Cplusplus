#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance)
    : Account {name, balance} {
}

// Withdraw:
//      Amount supplied to withdraw will be increased by the fee ($1.50) 
//      and then the updated amount will be withdrawn
//
bool Checking_Account::withdraw(double amount) {
    amount += per_with_fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << "]";
    return os;
}

