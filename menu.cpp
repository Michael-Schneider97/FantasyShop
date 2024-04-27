#include "menu.h"

// blank constructor
Menu::Menu() : title(""), optionChars(""), gameState(errorState) {}

// fancy constructor
Menu::Menu(std::string titleIn, std::string optionsIn, std::vector<std::string> &descriptionsIn) 
: title(titleIn), optionChars(optionsIn)
{
    // make sure you didn't mess up on your item counts
    // idk why the ide is marking this as an error yet. Will see if it compiles later on
    assert(optionsIn.size() == descriptionsIn.size());

    // deep copy input vector
    for(int i = 0; i < descriptionsIn.size(); i++)
    {
        optionDescriptions.push_back(descriptionsIn[i]);
    }    

    return;
}

// prints menu then retrieves option from user
// refactor this bad boy later to be consistent with update() hierarchy
void Menu::update()
{
    do
    {
        gameState = menuState;
        std::cout << std::endl << title << std::endl << std::endl;

        for(int i = 0; i < optionDescriptions.size(); i++)
        {
            std::cout << optionChars[i] << ": " << optionDescriptions[i] << std::endl;
        }

        std::cout << exitState << exitDesc << std::endl << std::endl << "Enter your option: ";
        gameState = retrieveMenuState();
    }
    while(gameState == menuState);
}

// uses cin or something of that nature to retrieve a menu state, does not let you use invalid ones
char Menu::retrieveMenuState()
{
    std::string input;
    std::cin >> input;

    if (input.size() > 1)
    {
        return menuState;
    }
    

    for(int i = 0; i < optionChars.size(); i++)
    {
        // checks if input is 1 char and matches an option
        if(input[0] == optionChars[i])
        {
            return optionChars[i];
        }
    }
    
    // special states
    if(input[0] == exitState)
    {
        return exitState;
    }

    // invalid response
    if(gameState == menuState)
    {
        std::cout << invalidInputMsg;
        return menuState;
    }
    }

char Menu::getGameState()
{
    return gameState;
}
