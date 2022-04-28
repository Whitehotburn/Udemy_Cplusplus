#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    try {

    std::unique_ptr<Account> test_chk = std::make_unique<Checking_Account>("Test", 100.0); // OK

    // std::unique_ptr<Account> test_chk_2 = std::make_unique<Checking_Account>("Test", -100.0); // IllegalBalanceException
    // test_chk->deposit(-100.0); // IllegalDepositException
    test_chk->withdraw(101.0); // InsufficientFundsException

    }
    catch (const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (const IllegalDepositException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch (const InsufficientFundsException &ex) {
        std::cerr << ex.what() << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

