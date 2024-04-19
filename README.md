# FantasyShop

Text based prototype for a game idea. This will iron out the game loop.

# Description of game loop

 * The game world will consist of a store with inventory containers. The player must sort, store, buy, and retrieve inventory. 
 * Orders will come from *characters*. 
 * Characters are NPCs who will have some quest they will be preparing for or returning from. Their requests will be relevant to what sorts of quests they are doing or have done. 
 * As characters do more quests they will level up and want more high-level items. 
 * The player can only obtain higher level items by upgrading their store. 
 * On top of managing the inventory, the player will need to manage costs against revenue. 
 * Special items can be obtained by contracting known adventurers or the adventurers guild. 
 * Contracts can be struck with special organizations. 
 * If the player does not possess what a customer is asking for, they can offer an alternative, which the customer will either accept or reject based on price, and level. 

# TODO LIST & TIMELINE

1. Consider implementation of menu managing class with tree or stack structure. 
2. Test and debug any issues in the inventory, item, slot, menu, and itemMasterList classes
3. Begin implementing base char object (has inventory, level) as well as the NPC and player specializations (consider using inheritance here)
4. Implement the shop class 
5. Implement elements for character simulation including AI, quests, organizations, orders, so on. 
6. Debug the simulation, characters, and shop