#ifndef item_h
#define item_h
#include <string>
#include <iostream>

class Item
{
    public:
    Item(std::string nameIn, std::string descriptionIn, int levelIn) : 
    name(nameIn), description(descriptionIn), level(levelIn) {}  // todo: update to include item type
    std::string getDescription() {return description;}
    std::string getName() {return name;}
    int getLevel() {return level;}
    void print() {std::cout << "\nItem Name: " << name << "\nItem Description: " << description << "\nItem Level: " << level << std::endl;  }

    protected:
    const std::string name;
    const std::string description;
    // item type
    const int level;
};

#endif