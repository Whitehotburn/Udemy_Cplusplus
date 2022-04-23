#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

// Checking Account is a type of Account
// Withdraw - $1.50 flat fee per withdrawal
// Deposit: - same as a regular account

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_with_fee = 1.5;  // compile-time constant, per class thing, not per object
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);    
    bool withdraw(double);
    // Inherits the Account::deposit methods
};

#endif // _CHECKING_ACCOUNT_H_
