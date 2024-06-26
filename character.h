/*
 * Base class for objects which contain
 * levels, inventories, and so on. This
 * class is inherited by the player object
 * and the npc object
 */
 
#ifndef character_h
#define character_h

#include "inventory.h"
#include "rpgClass.h"
#include <string>

class Character
{
	protected:
	Inventory inventory;
	int level;
	const int minLevel = 1;
	std::string name;
	Gender gender;
	int age;
	rpgClass charClass;
	
	public:
	void increaseLevel(unsigned int amount) {level += amount;}
	
	// returns a reference to the inventory to allow access of public inventory functions
	// probably functionally the same as just making inventory public itself
	// but oh well
	Inventory& getInventory() {return inventory;)
	
	// constructor
	Character(Inventory inventoryIn, int levelIn, std:string nameIn, int ageIn, Gender genderIn) : 
		inventory(inventoryIn, level(levelIn), name(nameIn), age(ageIn), gender(genderIn) {}
	
	// some standard getters
	int getLevel() const {return level;}
	std::string getName() const {return name;}
	int getAge() const {return age;}
	rpgClass getClass() const {return charClass;}
	Gender getGender const {return gender;}
	
	// updater
	void update()
	{
		inventory.update();
	}
};

#endif