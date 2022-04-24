// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"

// using namespace std;

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;
   
    // Accounts
    std::vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    std::vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // Checking

    std::vector<Checking_Account> chk_accounts;
    chk_accounts.push_back(Checking_Account {} );
    chk_accounts.push_back(Checking_Account {"Spongebob"} );
    chk_accounts.push_back(Checking_Account {"Patrick", 2000} );
    chk_accounts.push_back(Checking_Account {"Sandy", 5000} );

    display(chk_accounts);
    deposit(chk_accounts, 1000);
    withdraw(chk_accounts, 2000);

    // Trust

    std::vector<Trust_Account> tst_accounts;
    tst_accounts.push_back(Trust_Account {} );
    tst_accounts.push_back(Trust_Account {"Broke"} );
    tst_accounts.push_back(Trust_Account {"Rich", 50000} );
    tst_accounts.push_back(Trust_Account {"Middle-class", 5000, 5.0} );


    display(tst_accounts);
    deposit(tst_accounts, 5000);  // gives $50 bonus to all accounts, 'Rich' gets int_rate as well
    withdraw(tst_accounts, 5000); // fails - amount too much (except for 'Rich' account)
    withdraw(tst_accounts, 200);  // OK
    withdraw(tst_accounts, 100);  // OK
    withdraw(tst_accounts, 100);  // fails for $50k account "Rich" - 3 withdrawals exceeded
    withdraw(tst_accounts, 100);  // should fail

    // Can also do the following for testing Trust Account withdrawals
    //
    // for (size_t i{1}; i<=5; i++) {
    //     withdraw(tst_accounts, 1000);
    // }

    return 0;
}
