// inventories are made up of slots
// each slot has a unique item and a quantity of that item

#ifndef slot_h
#define slot_h

#include "item.h"
#include <cassert>

class Slot
{
    int currentStackSize;
    const int minQuantity = 1;
    const int maxQuantity;
    

    public:
    const int NULL_STACK_SIZE = -1;
    const Item *item;

    int getQuantity() const {return currentStackSize;}

    Slot(Item itemIn, int numIn) : item(new Item(itemIn)), currentStackSize(numIn), maxQuantity(itemIn.getMaxStack()) { assert(currentStackSize >= minQuantity); }
    bool remove(const Item itemIn, const int quantity = 1)
    {
        if(!item)
        {
            return false;
        }
        
        currentStackSize-= 1;
        if(currentStackSize < minQuantity)
        {
            Item *nullItem = new Item();
            item = nullItem;
            currentStackSize = NULL_STACK_SIZE;
            return true;
        }
    }

    bool add(const Item itemIn, const int quantity = 1)
    {
        if(currentStackSize + 1 <= maxQuantity && itemIn.getID() == item->getID())
        {
            currentStackSize++;
            return true;
        }

        return false;
    }
};

#endif