#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

// Trust Account is a type of Account
// Deposit - same as a regular account
// Withdraw adds the following functionality:
//     Cannot withdraw more than 20% of the balance at one time
//     Cannot withdraw more than 3 times per year

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
protected:
    int num_of_withdraw;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);    
    bool withdraw(double amount); // create custom withdraw method to add functionality
    bool deposit(double amount);  // modify existing savings deposit method to add $50 bonus over $5k deposit
};

#endif // _TRUST_ACCOUNT_H_
