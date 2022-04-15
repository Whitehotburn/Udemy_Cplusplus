#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

class Player {
private:
    string name {"XXXXX"}; // makes obvious what is happening with "this"
    int health;
    int xp;

public:
    // Overloaded Constructors
    Player();
    Player(string name_val);
    Player(string name_val, int health_val, int xp_val);
};

// Player::Player() {
//     name = "None";
//     health = 0;
//     xp = 0;
// }

    Player::Player() : name{"None"}, health{0}, xp{0} { 
    }

// Player::Player(string name_val) {
//     name = name_val;
//     health = 0;
//     xp = 0;
// }

    Player::Player(string name_val) : name{name_val}, health{0}, xp{0} {
    }

// Player::Player(string name_val, int health_val, int xp_val) {
//     name = name_val;
//     health = health_val;
//     xp = xp_val;
// }

    Player::Player(string name_val, int health_val, int xp_val) : name{name_val}, health{0}, xp{0} {
    }

int main() {
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};

    return 0;
}