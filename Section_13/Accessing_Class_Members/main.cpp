#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;

class Player {
public:
    // attributes
    string name;
    int health;
    int xp;

    // methods
    void talk(string text_to_say){
        cout << name << " says '" << text_to_say << "'" << std::endl;
    }
    bool is_dead();

};

class Account {
public:
    // attributes
    string name;
    double balance;

    // methods
    void deposit(double bal){
        balance += bal;
        cout << "Deposit was successful." << std::endl;
    }
    void withdraw(double bal){
        balance -= bal;
        cout << "Withdrawl was successful." << std::endl;
    }
    void display_balance() {
        cout << "The balance of " << name << " is " << balance << std::endl;
    }
};

int main() {

    Account frank_account;
    frank_account.name = "Frank's account";
    frank_account.balance = 5000;

    cout << "---- Frank's Account ----" << std::endl;
    frank_account.display_balance();
    frank_account.deposit(1000.0);
    frank_account.display_balance();
    frank_account.withdraw(500.0);
    frank_account.display_balance();

    Account *mary_account = new Account;
    mary_account->name = "Mary's account";
    mary_account->balance = 10000;

    cout << "\n---- Mary's Account -----" << std::endl;
    mary_account->display_balance();
    mary_account->deposit(4400.0);
    mary_account->display_balance();
    mary_account->withdraw(7700.0);
    mary_account->display_balance();

    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");

    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15;
    enemy->talk("I will destroy you!");

    return 0;
}