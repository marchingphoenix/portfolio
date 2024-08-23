#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Item.h"

// Create new Item with given name. Sets count to 1
Item::Item(string name) {
    this->itemName = name;
    this->itemCount = 1;
}

// Creates new Item with given name and count
Item::Item(string name, int count) {
    this->itemName = name;
    this->itemCount = count;
}

// Adds 1 to Item count
Item &Item::operator++() {
    ++itemCount;
    return *this;
}

// Returns current Item count
int Item::GetItemCount() {
    return itemCount;
}

// Returns Item count as histogram
string Item::GetItemHistogram() {
    ostringstream oss;
    oss << setw(itemCount) << setfill('*') << "";

    return oss.str();
}

// Prints Item details to console as int or histogram
void Item::PrintItem(bool histogram) {
    if (histogram) {
        cout << setw(11) << setfill(' ') << itemName;
        cout << ": " << GetItemHistogram() << endl;
    }
    else {
        cout << itemName << ": " << itemCount << endl;
    }
}

// Outputs Item details to provided file
void Item::PrintItem(std::ofstream &outFS) {
    outFS << itemName << " " << itemCount << endl;
}