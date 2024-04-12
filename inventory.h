#ifndef inventory_h
#define inventory_h

#include "item.h"
#include "slot.h"
#include <deque>

class Inventory
{
protected: 
    std::deque<Slot> inventory;
    const std::string name;


public:
    void display();
    void update();
    void addItem(Item item);
    Item removeItem();
};

#endif