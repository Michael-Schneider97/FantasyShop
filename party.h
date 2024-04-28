#ifndef party_h
#define party_h

// a data structure holding a set of 
// npc refs 
// An npc cannot be in multiple parties
// still not sure how i wanna do this

#include <vector>
#include "nonPlayer.h"

class Party
{
	std::vector<NonPlayer*> party;
	bool partyUp(NonPlayer* nonPlayerArray, int count)
	{
		for(int i = 0; i < count; i++)
		{
			if(nonPlayerArray[i].hasParty())
			{
				return false;￼
			}
			
			for(int i = 0; i < count; i++)
			{
				party.push_back(*nonPlayerArray[i]);
				nonPlayerArray[i].joinParty(this);  // probably somehow fucked this line up
			}
		}
		
		return true;
	}
	
	// calculate total power of the party
	int getPartyPower() const
	{
		for(int i = 0; i < party.size(); i++)
		{
			// add up attributes of equipped items
			
		}
	}

};


#endif