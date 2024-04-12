// currently being used for testing

#include "menu.h"
#include "item.h"

int main()
{
    const std::string menuOptions = "abcd";
    std::string title = "title";
    std::vector<std::string> vect;
    vect.push_back("a desc");
    vect.push_back("view item");
    vect.push_back("c desc");    
    vect.push_back("d desc");

    std::cout << "debug check/n";

    Menu menu(title, menuOptions, vect);
    Item item1("item1", "first item", 6);
    while(menu.getGameState() != 'e')
    {
        menu.update();
        switch(menu.getGameState())
        {
            case 'a' :
            break;

            case 'b' :
            item1.print();
            break;

            default :
            break;

        }
    }
}

