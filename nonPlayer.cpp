#include "nonPlayer.h"

// characters try to pick class aligned equipment 
// but will swap to other equipment if its vastly 
// superior or no class relevant equipment is available
void nonPlayer::selectEquipment()
{
	const int invalid = -1;
	int posFirstChoice, posSecondChoice;
	
	for(int i = 0; i < equipableTypes; i++)  // define in item.h
	{
		posFirstChoice = invalid;
		posSecondChoice = invalid;
		
		for(int j = 0; j < inventory.size(); j++)
		{
			
		}
	
	}
}