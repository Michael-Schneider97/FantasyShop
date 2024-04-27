#ifndef nonplayer_h
#define nonplayer_h

#include "character.h"

// non player character
class NonPlayer : public Character
{
	// constructor TODO
	NonPlayer();
	update() {character::update(); timerSinceOrder++; return;}
	
	// data section for actions
	int timerSinceOrder;
	int opinionOfStore;
	const int maxOpinion = 10;
	
};

#endif