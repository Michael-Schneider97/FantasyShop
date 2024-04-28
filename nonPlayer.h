#ifndef nonplayer_h
#define nonplayer_h

#include "character.h"
#include "party.h"

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
	
	// data section for actions
	int timerSinceOrder;
	int opinionOfStore;
	const int maxOpinion = 10;
	Party* currentParty = NULL;
	
};

#endif