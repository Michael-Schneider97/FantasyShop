/*
 * The character class is an object which defines
 * rpg - style classes (knight, mage, so on). 
 * These classes affect what types of items a 
 * character can obtain.
 */
 
 #ifndef charClass_h
 #define charClass_h
 
 // I really dont like the variable name here but cant think of anything better. 
 enum class rpgClass {MagicCaster, Knight, Summoner, Swordsman, Shopkeep};
 
 enum class gender {male, female, neither};
 
 // probably gonna redesign this bit later
 enum class relationship {nemesis, enemy, none, friends, rivals, family, siblings, lovers};

 #endif