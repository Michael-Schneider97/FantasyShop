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
	const int ATTRIBUTES = 4;
	const MAX_LEN = 10000;
	
	// loads the items into the data structure from the file
	void load()
	{
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
				Item itemIn(temp[0], temp[1], temp[2], temp[3];
			}
			catch() // add the appropriate exception
			{
				// handle the error
			}
			
			std::getline(FILE, temp[0];
		}
		
		return;
	}
	
	void save();
	
};

#endif