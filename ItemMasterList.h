#ifndef ItemMasterList_h
#define ItemMasterList_h

#include "item"
#include <deque>
#include <string>
#include <fstream>


class ItemMasterList
{
	std::deque<Item> itemMasterList;
	const std::string filename;
	const char DELIN = ',';
	const int ATTRIBUTES = 5;
	const MAX_LEN = 10000;
	
	// loads the items into the data structure from the file
	void load()
	{
		int itemID = 0;
		std::string temp[ATTRIBUTES];
		std::string temp;
		std::fstream FILE(filename, ios_base::in);
		if(!FILE)
		{
			return;
		}
		
		// if this loop fails theres a problem with the file format
		while(FILE.good())
		{
			for(int i = 0; i < ATTRIBUTES; i++)
			{
				std::getline(FILE, temp[i]);
			}
			
			// TODO MAKE CONSTRUCTOR FOR THIS IN ITEM CLASS
			try
			{
				// NOTE: when updating attributes, change this lime
				Item itemIn(temp[0], temp[1], temp[2], itemID++, temp[3], temp[4]);
			}
			catch() // add the appropriate exception
			{
				// handle the error
			}
			
			// if no errors occur, you can put itemId into the [] operator to get your item
			itemMasterList.push_back(itemIn);
			
			std::getline(FILE, temp[0];
		}
		
		return;
	}
	
	// we will only define this if we later decide to 
	// add master list editor otherwise its unneeded. 
	void save();
	
};

#endif