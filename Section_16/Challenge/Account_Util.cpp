#include <iostream>
#include "Account_Util.h"

// Display account objects in a vector of account object pointers
void display(const std::vector<Account *> &accounts) {
    std::cout << "\n*------------* Printing Accounts *------------*" << std::endl;
    for (auto acc_ptr: accounts) {
        std::cout << *acc_ptr << std::endl;
    }
}
// Deposits supplied amount to each Account object pointer in the vector
void deposit(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n*------------* Depositing to Accounts *------------*" << std::endl;
    for (auto acc_ptr: accounts) {
        if (acc_ptr->deposit(amount))
            std::cout << "Deposited " << amount << " to " << *acc_ptr << std::endl;
        else
            std::cout << "Failed deposit of " << amount << " to " << *acc_ptr << std::endl;
    }
}
// Withdraw amount from each Account object pointer in the vector
void withdraw(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n*------------* Withdrawing from Accounts *------------*" <<std::endl;
    for (auto acc_ptr: accounts)  {
        if (acc_ptr->withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << *acc_ptr << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << *acc_ptr << std::endl;
    } 
}
