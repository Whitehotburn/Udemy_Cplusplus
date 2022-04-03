/*
Pseudocode
Prompt the user to enter the number of rooms
Display the number of rooms
Display price per room

Display cost: # of rooms * price per room
Display tax: # of rooms * price per room * tax rate
Display total estimate: cost + tax
Display estimate expiration time
*/

#include <iostream>
using namespace std;

int main() {
    cout << "Hello, welcome to Mitchell's cleaning service" << endl;
    cout << "How many rooms would you like cleaned? ";

    int number_of_rooms{0};
    cin >> number_of_rooms;

    cout << "\nEstimate for carpet cleaning service: " << endl;
    cout << "Number of rooms: " << number_of_rooms << endl;

    const double price_per_room{32.50};

    cout << "Price per room: $" << price_per_room << endl;

    int cost = number_of_rooms * price_per_room;
    const double tax_rate = 0.06;
    double total_tax = cost * tax_rate;
    const int estimate_expiry{30}; // days

    cout << "Cost: $" << cost << endl;
    cout << "Tax: $" << total_tax << endl;
    cout << "================================" << endl;
    cout << "Total estimate: $" << cost + total_tax << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days" << endl;

    return 0;
}