#ifndef inventory_h
#define inventory_h

#include "item.h"
#include "slot.h"
#include <deque>
#include <string>

class Inventory
{
protected: 
    std::deque<Slot> inventory;
    const std::string name;
    const int size;
    const int NOT_FOUND = -1;
    
    int getLocationOf(const Item itemIn, int *quantity);


public:
    int getFreeSlots();
    void consolidate();
    Inventory(std::string nameIn, const int sizeIn);
    int getCount(const Item itemIn);
    void display();
    void update();
    bool addItem(const Item itemIn, const int quantity);
    bool removeItem(const Item itemIn, const int quantity);
    int getIndex(const Item itemIn, const int slotId);
    void passItem(Inventory destination, const Item itemToPass, const int quantity);
    int getUsedSlots();
    
};

#endif

// NOTE: may adjust the status reporting to a char system
// with each char represting success/failure and the reason for such 
// see below
/*
{
	 const char SUCCESS = 's',
				NO_SLOTS_AVAIL = 'f',
				SLOT_FULL = 'l',
				 

}
*/