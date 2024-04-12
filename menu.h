// menu class for displaying a custom menu to the console
// and allowing someone to input an option to control the menu

#ifndef menu_h
#define menu_h


#include <vector>
#include <string>
#include <cassert>
#include <iostream>

// two vectors hold data. One is a set of string descriptions the other is a set of char identifiers
// we also have a title
// menu sets gamestate which can be read externally
class Menu
{
    private:
    char retrieveMenuState();
    
    public:
    
    // constructor 1 lets you pass in a string of char options and a vector of strings to make things easy
    Menu(std::string titleIn, std::string optionsIn, std::vector<std::string> &descriptionsIn);

    // base constructor lets you set things up as you go instead, leaving everything blank
    Menu();

    // displays the menu and waits for input
    void update();
    char getGameState();

    // data section
    protected:
    std::string title;
    std::string optionChars;
    std::vector<std::string> optionDescriptions;
    char gameState;
    const char exitState = 'e';     // exit sentinel
    const char errorState = '`';    // sentinel cause ill never use this in menus
    const char menuState = 'm';     // this will be reserved for the menu
    const std::string invalidInputMsg = "\nInvalid text received, try again.\n";
    const std::string exitDesc = ": Exit this menu\n";
};

#endif