#ifndef item_h
#define item_h
#include <string>
#include <iostream>

class Item
{
    public:
    Item(std::string nameIn, std::string descriptionIn, int levelIn, int itemIDIn, int stackSizeIn) : 
    name(nameIn), description(descriptionIn), level(levelIn), itemID(itemIDIn), stackSize(stackSizeIn) {} // todo: update to include item type
    std::string getDescription() {return description;}
    std::string getName() {return name;}
    int getLevel() const {return level;}
    void print() const {std::cout << "\nItem Name: " << name << "\nItem Description: " << description << "\nItem Level: " << level << std::endl;  }
    int getMaxStack() const {return stackSize;}
    int getID() const {return itemID;}
    std::string getName() const {return name;}
    // defualt constructor makes a null Item
    Item() : name(""), description(""), level(NULL_LEVEL), itemID(NULL_ITEMID), stackSize(0) {}


    // cast item to bool to test empty
    explicit operator bool() { if(name == "" && description == "" && level == NULL_LEVEL) {return false;} return true; }


    protected:
    const std::string name;
    const std::string description;
    // item type
    const int level;
    const int itemID;
    const int NULL_ITEMID = -1;
    const int stackSize;
    const int NULL_LEVEL = -1;

};

#endif