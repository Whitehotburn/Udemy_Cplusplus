#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

int main() {
    
// Use the account class
    std::cout << "\n=== Account =============================" << std::endl;
    Account acc{};
    acc.deposit(2000.0);
    acc.display_balance();
    acc.withdraw(500.0);
    acc.display_balance();

    std::cout << std::endl;

    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->display_balance();
    p_acc->withdraw(500.0);
    p_acc->display_balance();
    delete p_acc;

// Use the Savings Account class

    std::cout << "\n=== Savings Account =====================" << std::endl;
    Savings_Account sav_acc{};
    sav_acc.deposit(2000.0);
    sav_acc.display_balance();
    sav_acc.withdraw(500.0);
    sav_acc.display_balance();

    std::cout << std::endl;

    Savings_Account *p_sav_acc{nullptr};
    p_sav_acc = new Savings_Account{};
    p_sav_acc->deposit(1000.0);
    p_sav_acc->display_balance();
    p_sav_acc->withdraw(500.0);
    p_sav_acc->display_balance();
    delete p_sav_acc;

    std::cout << "\n=========================================" << std::endl;
    return 0;
}