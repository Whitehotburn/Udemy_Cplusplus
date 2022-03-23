#include <iostream>
using namespace std;

int main() {

cout << "Hello, welcome to Mitchell's Carpet Cleaning Service" << endl;

int num_small_rooms{0};
cout << "How many small rooms would you like cleaned? ";
cin >> num_small_rooms;

int num_large_rooms{0};
cout << "How many large rooms would you like cleaned? ";
cin >> num_large_rooms;

cout << "\nEstimate for carpet cleaning service:" << endl;
cout << "Number of small rooms: " << num_small_rooms << endl;
cout << "Number of large rooms: " << num_large_rooms << endl;
cout << "Price per small room: $25" << endl;
cout << "Price per large room: $35" << endl;

const double price_small_room{25};
const double price_large_room{35};
const double tax_rate{0.06};

double subtotal = (num_small_rooms * price_small_room) + (num_large_rooms * price_large_room);
double tax = subtotal * tax_rate;

cout << "Cost : $" << subtotal << endl;
cout << "Tax : $" << tax << endl;
cout << "================================" << endl;

double total_estimate = subtotal + tax;
cout << "Total estimate: $" << total_estimate << endl;
cout << "This estimate is valid for 30 days" << endl;

return 0;
}
