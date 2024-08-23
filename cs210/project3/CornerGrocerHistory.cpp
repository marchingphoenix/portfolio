#include <iostream>
#include <iomanip>
#include <string>

#include "ItemList.h"

using namespace std;

// creates a string of fill characters repeated count times.
string nCharString(char fill, int count) {
    ostringstream oss;
    oss << setw(count) << setfill(fill) << "";

    return oss.str();
}

// Outputs Menu Header
void outputMenuHeader() {
    cout << nCharString('*', 35) << endl;
    cout << nCharString('*', 12) << " Main Menu ";
    cout << nCharString('*', 12) << endl;
}

// Output formatted menu option line
void outputMenuOption(int menuOrder, string menuOption) {
    cout << "* " << menuOrder << setw(30) << setfill('.');
    cout << menuOption << " *" << endl;
}

// Outputs Menu Options
void outputMenuOptions() {
    map<int, string> optionsList = {
        {1, "Item Lookup"},
        {2, "Print Full List with Counts"},
        {3, "Print Full List as Histogram"},
        {4, "Exit"}
    };
    map<int, string>::iterator it;

    for (it = optionsList.begin(); it != optionsList.end(); it++) {
        outputMenuOption(it->first, it->second);
    }
}

// Handling for menu option 1
void lookupItem(ItemList* itemList) {
    // item name storage var
    string itemName;

    cout << "Please input item name (case sensitive): ";
    cin >> itemName;
    itemList->LookupItem(itemName);
}

// Main Menu. Prompts user for valid input and executes selection
void menu(ItemList* itemList) {
    char selection;
    bool retry = true;
    cout << endl;

    while (retry) {
        outputMenuHeader();
        outputMenuOptions();
        cout << nCharString('*', 35) << endl << endl;
        cout << "Please input selection: ";
        cin >> selection;

        switch (selection) {
            case '1':
                lookupItem(itemList);
                cout << endl;
                break;
            case '2':
                itemList->PrintAllItems(false);
                cout << endl;
                break;
            case '3':
                itemList->PrintAllItems(true);
                cout << endl;
                break;
            case '4':
                cout << "Exiting..." << endl;
                retry = false;
                break;
            default:
                cout << "Invalid Menu Selection: " << selection;
                cout << endl << endl;
                cin.sync();
                cin.clear();
                break;
        }
    }
}

int main() {
    // backup file name
    const string BACKUP_FILE = "frequency.dat";
    // intput file name
    const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
    // ItemList object pointer
    ItemList* itemList;

    try {
        // Try to create Item List
        itemList = new ItemList(BACKUP_FILE, INPUT_FILE);
    }
    catch(const runtime_error& e) {  // Unable to open input or backup files
        std::cerr << e.what() << '\n';
        return 1;
    }

    // execute menu selection
    menu(itemList);

    return 0;
}