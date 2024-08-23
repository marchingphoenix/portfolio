#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <string>
#include <fstream>
#include <map>

#include "Item.h"

class ItemList {
    public:
        ItemList(std::string backupFileName, std::string inputFileName);
        void LookupItem(std::string itemName);
        void PrintAllItems(bool histogram);
    private:
        std::map<std::string, Item> itemList;
        void ProcessNextItem(std::ifstream &inFS);
        void LoadBackup(std::string backupFileName);
        void TabulateSales(std::string backupFileName, std::string inputFileName);
};

#endif