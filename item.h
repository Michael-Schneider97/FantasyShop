#ifndef item_h
#define item_h
#include <string>
#include <iostream>
#include "rpgClass.h"

enum class itemType {weapon, potion, scroll, boot, armor, glove, helmet, ring, junk};
float valueMultiplier[9] = {9, 2, 2, 7, 7, 7, 7, 4, 0};
const int equippableTypes = 7;

class Item
{
    public:
    
    
    // regular constructor
    Item(std::string nameIn, std::string descriptionIn, int levelIn, int itemIDIn, int stackSizeIn, rpgClass itemClassIn) : 
    name(nameIn), description(descriptionIn), level(levelIn), itemID(itemIDIn), stackSize(stackSizeIn), itemClass(itemClassIn) {} // todo: update to include item type
    std::string getDescription() {return description;}
    int getLevel() const {return level;}
    void print() const {std::cout << "\nItem Name: " << name << "\nItem Description: " << description << "\nItem Level: " << level << std::endl;  }
    int getMaxStack() const {return stackSize;}
    int getID() const {return itemID;}
    std::string getName() const {return name;}
    int getValue() {return level * valueMultiplier[static_cast<int>(thisItemType)];}    // perhaps we redesign this later
    itemType getType() const {return thisItemType;}
    
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
    rpgClass itemClass;
    itemType thisItemType;

};

#endif