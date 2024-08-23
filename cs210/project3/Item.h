#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <fstream>

class Item {
    public:
        Item(std::string name);
        Item(std::string name, int count);
        Item& operator++();
        int GetItemCount();
        void PrintItem(bool histogram);
        void PrintItem(std::ofstream &outFS);
    private:
        std::string GetItemHistogram();
        std::string itemName;
        int itemCount;
};

#endif