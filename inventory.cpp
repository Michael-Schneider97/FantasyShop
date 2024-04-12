#include "inventory.h"

// removes empty slots
void Inventory::update()
{
    for(auto i = inventory.begin(); i != inventory.end(); i++)
    {
        if(!inventory[std::distance(i, inventory.begin())].item)
        {
            inventory.erase(i);
        }
    }
}

void Inventory::display()
{
    update();

    // prints out each item
    std::cout << name << std::endl << std::endl;
    
    for(int i = 0; i < inventory.size(); i++)
    {
        inventory[i].shortPrint();
    }

    std::cout << std::endl;
}

// todo implement adding items from the void, sending them them there, and the passItem function
// automatic slot selection, checking if inventory is full



bool Inventory::addItem(Item item)
{

}

bool Inventory::removeItem()
{

}

// attempt to pass item from inventory a to b
// failure causes nothing to happen and prints an error message to console
void Inventory::passItem(Inventory destination, const Item itemToPass, Const int quantity = 1)
{
    const Slot slot = removeItem(itemToPass, quantity);

    if(!item)
    {
         // item does not exist in the inventory
        // print error message
        return;
    }

    if(!destination.addItem(item, quantity))
    {
    // cannot add item either due to lack of space or 
    // the container is not allowed to contain it 
    // print error
    addItem(item, quantity);
    return;
}

// successful passage of item
return;
}
