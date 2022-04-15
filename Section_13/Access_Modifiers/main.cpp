#include <iostream>
#include <string>

using std::string;
using std::cout;

class Player {
private:

    // attributes
    string name {"Player"};
    int health;
    int xp;
public:
    //methods
    void talk(string text_to_say) {
        cout << name << " says " << text_to_say << std::endl;
    }
    bool is_dead();
};

int main() {

    Player frank;
    // frank.name = "Frank"; error - trying to change private
    // cout << frank.health << endl - error, declared private here
    frank.talk("Hello there!");
    return 0;
}