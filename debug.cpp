/* 
 * a menu for debugging different systems 
 */
 
 #include "item.h"
 #include "menu.h"
 #include "inventory.h"
 #include "slot.h"
 
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
				 itemOptions = "cgpb";
	 
	 
	 std::vector<std::string> descriptions("Debug Inventory", "Debug Slot", "Debug Item"),
							 invDescriptions(),
							 slotDescriptions("Create Slot With Custom Item", "Add item from selection to slot", "remove item from selection from slot", "test getters"),
							 itemDescriptions("Create Custom Item", "Get Item Data", "Print Item","Check Bool Operator");
	 
	 // probably gonna refactor this after we 
	 // setup the menu data structure. 
	 // till then ill use this quick and dirty
	 // solution
	
	 Menu debugMainMenu(title, options, descriptions);
	 Menu debugInventory(invTitle, invOptions, invDescriptions);
	 Menu debugSlot(slotTitle, slotOptions, slotDescriptions);
	 Menu debugItem(itemTitle, itemOptions, itemDescriptions);
	 
 }
 