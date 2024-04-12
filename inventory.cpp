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

Inventory::Inventory(std::string nameIn, const int size)
: name(nameIn), size(sizeIn) {}


// util func for checking if an item is in the inventory somewhere
// returns the first element to contain the item in a slot with space for more
// THE QUANTITY ARGUMENT WILL BE MODIFIED IF THE CONTAINER HAS
// FEWER/MORE THAN THE SPECIFIED AMOUNT
int getLocationOf(const Item itemIn, int *quantity = NULL)
{

	//todo: add checking for if we have x amount of this item in the slot
	// return early if that quantity < stacksize and that the itemIn is valid
	std::deque<int> listOfPositions;
	std::deque<int> listOfQuantities;
	int position = -1;

	if(!quantity)
	{
		quantity = new int(1);
	}
	
	for(int i = 0; i < inventory.size(); i++)
	{
		if(itemIn.getID() ==inventory[i].item->getID())
		{
			listOfPositions.push_back(i);
			listOfQuantities.push_back(inventory[i].item->getID();
		}
	}
	
	for(int i = 0; i < listOfQuantities.size(); i++)
	{
		if(listOfQuantities[i] < inventory[listOfPositions[i]].item->getStackSize())
		{
			quantity = listOfQuantities[i];
			position = listOfPositions[i];
		}
	}
	
	return position;
}



// todo implement adding items from the void, sending them them there, and the passItem function
// automatic slot selection, checking if inventory is full


// add an item that is not currently in an inventory
bool Inventory::addItem(const Item &item)
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
