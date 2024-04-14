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
    const int size;
    const int NOT_FOUND = -1;
    
    int getLocationOf(const Item itemIn);


public:
    Inventory(std::string nameIn, const int sizeIn);
    int getCount(const Item itemIn);
    void display();
    void update();
    bool passItem
    bool addItem(Item item);
    Item removeItem();
    
};

#endif

// NOTE: may adjust the status reporting to a char system
// with each char represting success/failure and the reason for such 
// see below

{
	 const char SUCESS = 's',
				NO_SLOTS_AVAIL = 'f',
				SLOT_FULL = 'l',
				 

}