/*
 * The character class is an object which defines
 * rpg - style classes (knight, mage, so on). 
 * These classes affect what types of items a 
 * character can obtain.
 */
 
 #ifndef charClass_h
 #define charClass_h
 
 
 // we may change this to a class and hold a vector 
 // loaded from a file but for now this is sufficient 
 struct charClass
 {
	 const std::string name, description;
	 const int ID;
 };
 
 #endif