#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, num_of_withdraw{0} {
}

// Deposit:
//      if amount is over $5k, add $50.00 bonus
bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}

// Withdraw:
//      tracking variable "num_of_withdrawals" to track annual withdrawals - limited to max of 3 per year
//      cannot withdraw more than 20% of account balance at one time
bool Trust_Account::withdraw(double amount) {
    if (balance-amount <= 0) {
        std::cout << "Failed Withdraw of " << amount << " from " << "[Account: " << name << ": " << balance << "]" << std::endl;
        return false;
    } else if (num_of_withdraw >= max_withdrawals) {
        std::cout << "Withdraw FAILED - number of annual withdrawals exceeded for this account!" << std::endl;
        return false;
    } else if (amount > (balance * max_withdraw_percent)) {
        std::cout << "Withdraw FAILED - attempted to withdraw " << amount << " from the account, >20% of the account balance!" << std::endl;
        return false;
    } else {
        balance -= amount;
        num_of_withdraw += 1;
        return true;
    }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate 
        << "%, # withdrawals: " << account.num_of_withdraw << "]";
    return os;
}
