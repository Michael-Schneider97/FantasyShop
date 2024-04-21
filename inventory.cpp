#include "inventory.h"

/* Function which removes dead slots
 * Call this function before calling
 * any non-const function, or any 
 * function which modifies or reads
 * slots in the inventory data structure. 
 */
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

/* Function which print the inventory
 * on the screen. 
 * We might refactor this to return a
 * string to be printed by a separate
 * stream object. 
 */
void Inventory::display()
{
    update();
    std::cout << name << std::endl << std::endl;
    
    for(int i = 0; i < inventory.size(); i++)
    {
        inventory[i].shortPrint();
    }

    std::cout << std::endl;
}

// constructor
Inventory::Inventory(std::string nameIn, const int size)
: name(nameIn), size(sizeIn) {}

// get the nth slot with the matching item
// should probably have zero indexed this 
int Inventory::getIndex(const Item itemIn, const int slotId = 1)
{
	int slotIteration = 1;

	for(int i = 0; i < inventory.size(); i++)
	{
		if(inventory[i].item->getID() == itemIn.getID())
		{
			if(slotIteration == slotId)
			{
				return i;
			}
			
			else
			{
				slotIteration++;
			}
		}
	}
	
	return NOT_FOUND;
}

// get total count of some item
int Inventory::getCount(const Item itemIn)
{
	int currentIndex = 0;
	int count = 0;
	
	currentIndex = getIndex(itemIn);
	
	while(currentIndex!= NOT_FOUND)
	{
		count+= inventory[currentIndex].getQuantity();
		currentIndex = getIndex(itemIn);
	}
	
	return count;
}

// might delete this method
// TODO SPLIT INTO TWO FUNCTIONS
// FIRST FINDS IF WE HAVE X AMOUNT OF Y ITEM
// SECOND FINDS IF WE HAVE SLOT WITH Y ITEM AND SPACE FOR X AMOUNT
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
		if(listOfQuantities[i] < inventory[listOfPositions[i]].item->getMaxStack())
		{
			quantity = listOfQuantities[i];
			position = listOfPositions[i];
		}
	}
	
	return position;
}

// returns the current open slots
int Inventory::getFreeSlots() const
{
	update();
	return inventory.size() - size;
}

// consolidates the inventory into fewest possible slots
// TODO complete this function
void Inventory::consolidate()
{
	update();

	// go slot by slot, skipping full ones
	for(int i = 0; i < inventory.size(); i++)
	{
		if(inventory[i].isFull())
		{
			continue;
		}
	}
}

// add an item that is not currently in an inventory
bool Inventory::addItem(const Item itemIn, const int quantity = 1)
{

	int quantityToAdd = quantity;
	// do we have space?
	int spaces = 0;
	spaces += (getFreeSlots() * itemIn.getMaxStack());
	
	// now add all the space in slots which are not full
	const int totalSlots = getSlotsWith(itemIn);
	for(int i = 0; i < totalSlots; i++)
	{
		spaces += (inventory[getIndex(itemIn, i+1)].getMaxStack() - inventory[getIndex(itemIn, i+1)].getQuantity());
	}
	
	// not enough space in this inventory
	if(spaces < quantity)
	{
		return false;
	}
	
	// this is where we might do a level check, should we 
	// implement levels within the inventory class
	
	// we fill any slots of this item with empty space remaining
	for(int i = 0; i < totalSlots; i++)
	{
		// code smell
		int spaceThisSlot = (inventory[getIndex(itemIn, i+1)].getMaxStack() - inventory[getIndex(itemIn, i+1)].getQuantity());
		
		if(spaceThisSlot == 0)
		{
			continue;
		}
		
		else if(spaceThisSlot < quantityToAdd)
		{
			if(inventory[getIndex(itemIn, i+1)].addItem(itemIn, spaceThisSlot))
			{
				quantityToAdd-=spaceThisSlot;
				continue;
			}
		}
		else
		{
			if(inventory[getIndex(itemIn, i+1)].addItem(itemIn, quantityToAdd))
			{
				return true;
			}
		}
	}
	
	// we have run out of slots which already contain the item, so now we make new ones
	Slot newSlot(itemIn, itemIn.getMaxStack());
	
	while(quantityToAdd > itemIn.getMaxStack())
	{
		inventory.push_back(newSlot);
		quantityToAdd-=itemIn.getMaxStack();
	}
	
	Slot newNewSlot(itemIn,quantityToAdd);
	return true;
}

// remove an item to the void
// it is the responsibility of the one calling this function to 
// make sure the inventory has the item and the quantity
bool Inventory::removeItem(const Item itemIn, const int quantity = 1)
{
	int quantityToDelete = quantity;
	if(getCount(itemIn) < quantity || getIndex(itemIn) == NOT_FOUND)
	{
		return false;
	}
	
	while(quantityToDelete > 0)
	{
		int currentIndex = getIndex(itemIn, 1);
		if(inventory[currentIndex].getQuantity() < quantityToDelete)
		{
			// NOTE: If we update to stack sizing being dependent
			// on the container this will introduce a logic bug
			// and well need to pull our second variable in this
			// call from the inventory itself, not itemIn
			inventory[currentIndex].removeItem(itemIn, itemIn.getMaxStack());
			quantityToDelete-=itemIn.getMaxStack();
		}
		else
		{
			inventory[currentIndex.removeItem(itemIn, quantityToDelete);
		}
	}
	
	return true;
}

// attempt to pass item from inventory a to b
// possibly will refactor this to return bool
void Inventory::passItem(Inventory destination, const Item itemToPass, Const int quantity = 1)
{
    if(!removeItem(itemToPass, quantity))
    {
	    return;
    }
    
    if(!destination.addItem(item, quantity))
    {
	    // undo removal
	    addItem(item, quantity);
	    return;
    }

	// successful passage of item
	return;
}
