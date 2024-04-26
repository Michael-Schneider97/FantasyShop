/* 
 * a menu for debugging different systems 
 */
 
 #include "item.h"
 #include "menu.h"
 #include "inventory.h"
 #include "slot.h"
 #include <string>
 #include <vector>
 
 // debug major systems here
 void debug()
 {
	 const
	 std::string title = "Debug Main Menu",
				 options = "ist",
				 invTitle = "Debug Inventory Menu",
				 invOptions = "",
				 slotTitle = "Debug Slot Menu",
				 slotOptions = "csrt",
				 itemTitle = "Debug Item Menu",
				 itemOptions = "cgpb",
				 itemMenuOpts = "123";
	 
	 
	 std::vector<std::string> descriptions("Debug Inventory", "Debug Slot", "Debug Item"),
							 invDescriptions(),
							 slotDescriptions("Create Slot With Custom Item", "Add item from selection to slot", "remove item from selection from slot", "test getters"),
							 itemDescriptions("Create Custom Item", "Get Item Data", "Print Item","Check Bool Operator"),
							 itemMenuDescs("Item 1", "Item 2", "Item 3");
	 
	// probably gonna refactor this after we 
	// setup the menu data structure. 
	// till then ill use this quick and dirty
	// solution
	
	Menu debugMainMenu(title, options, descriptions);
	Menu debugInventory(invTitle, invOptions, invDescriptions);
	Menu debugSlot(slotTitle, slotOptions, slotDescriptions);
	Menu debugItem(itemTitle, itemOptions, itemDescriptions);
	Menu itemMenu("Item Menu", "123", itemMenuDescs);

	// variables used for debugging
	Item *item;
	Slot *slot;
	Inventory *inventory;
	Item item1("test item 1", "this is a test item", 1, 1, 1, 1), item2("test item 2", "this test item has some interesting attributes", -100, -1, 0, 

	// what youre about to see is going to be a complete mess
	// prepare yourself. 
	while(debugMainMenu.getGameState() != 'e') // TODO make an enum/public member for special menu states
	{
		debugMainMenu.update();
		switch(debugMainMenu.getGameState())
		{
			case options[0] :
				while(debugInventory.getGameState() != 'e')
				{
					debugInventory.update();
					switch(debugsInventory.getGameState())
					{
						case invOptions[0] :
							// TODO
							
					} 
				}
				break;
				
			case options[1] : 
				while(debugSlot.getGameState() != 'e')
				{
					debugSlot.update();
					switch(debugSlot.getGameState())
					{
						case slotOptions[0] : 
							{
								// this code is so not good
								// it is in fact very bad
								std::string tempName, tempDescription;
								int tempLevel, tempStacksize, tempId, tempRpgClass, tempCount;
												
								const std::string namePrompt = "item name",
													descPrompt = "item desc",
													levPrompt = "item level",
													stackPrompt = "item max stacks",
													idPrompt = "item id",
													rpgPrompt = "item class";
								
													
								std::cout << namePrompt << ": ";
								std::cin >> tempName;
								std::cout << descPrompt << ": ";
								std::cin >> tempDescription;
								std::cout << levPrompt << ": ";
								std::cin >> tempLevel;
								std::cout << stackPrompt << ": ";
								std::cin >> tempStackSize;
								std::cout << idPrompt << ": ";
								std::cin >> tempId;
								std::cout << rpgPrompt << ": ";
								std::cin >> tempRpgClass;
								std::cout << "actual stack amount: ";
								std::cin >> tempCount;
								
								if(slot)
								{
									delete slot;
								}
								
								Item tempItem(tempName, tempDescription, tempLevel, tempId,tempStackSize, static_cast<rpgClass>(tempClass));
								slot = new Slot(tempItem, tempCount);
							}
						
						case slotOptions[1] :
							{
								// oh god oh fuck another menu
								std::cout << "Pick from the items below";
								while(itemMenu.getGameState != 'e')
								{
									
								}
							}
					}
				}
				break;
				
			case options[2] :
				while(debugItem.getGameState(( != 'e')
				{
					debugItem.update();
					switch(debugItem.getGameState())
					{
						case itemMenuOpts[0] : 
						
						case itemMenuOpts[1] :
						
						case itemMenuOpts[2] :
					}
				}
				break;
			
			default :
				break;
		}
	}
	
	 
 }
 