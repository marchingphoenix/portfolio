#include <iostream>
#include <iomanip>

using namespace std;

#include "ItemList.h"

// Create new ItemList from backup file or from input file
ItemList::ItemList(string backupFileName, string inputFileName) {
    try { // Load from backup if exists.
        this->LoadBackup(backupFileName);
    }
    catch(const runtime_error& e) {  // Backup doesn't exist
        try {  // Try building itemList from input file
            this->TabulateSales(backupFileName, inputFileName);
        }
        catch(const runtime_error& e) {  // Unable to open either input file or backup file
            throw;
        }
    }
    cout << "Item calculations are ready." << endl;
}

// Processes next item in file and either adds new item or updates found item
void ItemList::ProcessNextItem(ifstream &inFS) {
    // storage var for item name
    string itemName;

    // load next name from list
    inFS >> itemName;
    
    // Check if item already exists in itemList
    if (this->itemList.find(itemName) == itemList.end()) {
        // if item not in itemList, add new item
        this->itemList.insert(make_pair(itemName, Item(itemName)));
    }
    else {
        // update item count
        ++this->itemList.find(itemName)->second;
    }
}

// Loads itemList from backup file
void ItemList::LoadBackup(string backupFileName) {
    // backup file stream
    ifstream backupFS;
    // storage var for next name in file
    string name;
    // storage var for next count in file
    int count;

    // Ensure backup file exists and can be opened
    backupFS.open(backupFileName);
    if (!backupFS.is_open()) {
        // raise exception if file can't be read
        throw runtime_error("File " + backupFileName + " Not Found");
    }

    cout << "Loading data from backup: " << backupFileName << endl;

    // loop through backup file to generate itemList
    while (!backupFS.eof()) {
        backupFS >> name;
        backupFS >> count;
        this->itemList.insert(make_pair(name, Item(name, count)));
    }
}

// Loads item counts from input file, generates backup file, and returns itemList map.
void ItemList::TabulateSales(string backupFileName, string inputFileName) {
    // input file stream
    ifstream inFS;
    // output file stream
    ofstream outFS;
    // iterator object for itemList. Used for backup generation.
    map<string, Item>::iterator it;

    // open input file
    cout << "Tabulating Item Sales..." << endl;
    inFS.open(inputFileName);
    if (!inFS.is_open()) {
        throw runtime_error("Could not open file " + inputFileName);
    }

    // open output file
    outFS.open(backupFileName);
    if (!outFS.is_open()) {
        throw runtime_error("Could not open file " + backupFileName);
    }
    while (!inFS.eof()) {
        this->ProcessNextItem(inFS); // update itemList with next line
    }
    inFS.close();  // close input file.

    // generate backup file by iterating over itemList
    for (it = this->itemList.begin(); it != this->itemList.end(); it++) {
        it->second.PrintItem(outFS);  // second is the value of the key value pair
    }
    outFS.close();  // close output file.
}

// Print all Items from ItemList with counts or with histogram
void ItemList::PrintAllItems(bool histogram) {
    map<string, Item>::iterator it;
    int pad = histogram ? 3 : 5;

    cout << endl;
    cout << string(pad, ' ') << "Item List ";
    cout << (histogram ? "Histogram" : "Counts") << endl;
    cout << setw(25) << setfill('-') << "" << endl;

    for (it = this->itemList.begin(); it != this->itemList.end(); it++) {
        it->second.PrintItem(histogram);  // second is the value of the key value pair
    }
}

// Lookup item by name and outputs count if found
void ItemList::LookupItem(string itemName) {
    // lookup result
    map<string, Item>::iterator it;
    // count of found item
    int count;

    // lookup item
    it = this->itemList.find(itemName);

    if (it == this->itemList.end()) { // item not found
        cout << "Item " << itemName << " not found in Item List." << endl;
    }
    else {
        count = it->second.GetItemCount();
        cout << "Item " << itemName << " found " << count;
        cout << (count == 1 ? " time." : " times.") << endl;
    }
}