#ifndef nonplayer_h
#define nonplayer_h

#include "character.h"
#include "party.h"
#include "inventory.h"

class Party;

// non player character
class NonPlayer : public Character
{
	// constructor TODO
	NonPlayer();
	update() {character::update(); timerSinceOrder++; return;}
	
	// TODO
	bool joinParty(Party *party);
	bool leaveParty();
	void selectEquipment();
	Inventory& getEquippedItems() {return equippedItems;}
	
	// equipped items
	Inventory &equippedItems;
	
	// data section for actions
	int timerSinceOrder;
	int opinionOfStore;
	const int maxOpinion = 10;
	Party* currentParty = NULL;
	
};

#endif