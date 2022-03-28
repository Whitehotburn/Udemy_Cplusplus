#include <iostream>

using namespace std;

int main() {

    int change_amount {0};

    cout << "Enter an amount in change_amount: ";
    cin >> change_amount;

    int dollars{}, quarters{}, dimes{}, nickels{}, pennies{};

    dollars = change_amount/100;
    change_amount %= 100;

    quarters = change_amount/25;
    change_amount %= 25;

    dimes = change_amount/10;
    change_amount %= 10;

    nickels = change_amount/5;
    change_amount %= 5;

    pennies = change_amount;

    cout << "You can provide change as follows:" << endl;
    cout << "dollars  : " << dollars << endl;
    cout << "quarters : " << quarters << endl;
    cout << "dimes    : " << dimes << endl;
    cout << "nickels  : " << nickels << endl;
    cout << "pennies  : " << pennies << endl;

    return 0;

}
