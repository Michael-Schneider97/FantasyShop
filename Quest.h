#ifndef quest_h
#define quest_h

#include <string>
#include "item.h"

class Quest
{
	// code smell
	std::string name;
	std::string description;
	
	int level; // beginning to think i need a level object 
	const bool repeatable; // radiant quests
	int partySize; // the expected party size for this quest.
	int reward; // money received for success
	int timeTaken; // how much game time it takes to complete
	// constructor 
	Quest() {}
	
	// success of a quest depends on party size, level, and equipment
	// for each class, a given piece of equipment has a level. 
	// if a relevant equipment slot is empty, then the level is 0
	// the levels of items are calculated together to get a quotient of power
	// if, for example, a knight goes on with no weapon, they should not be likely to succeed 
	// however, an overleveled party beinging an underlevelled friend is fair game
	// the purpose of this is if a party comes, asks the player for equipment they dont have
	// they can give lower level equipment but the party may fail their quest or die
	// thereby returning angry
	bool simulateQuestAttempt(); // TODO
};

#endif