// currently being used for testing

#include "menu.h"
#include "item.h"
#include "slot.h"

int main()
{
    const std::string menuOptions = "abcdf";
    std::string title = "title";
    std::vector<std::string> vect;
    vect.push_back("add too many");
    vect.push_back("increment it");
    vect.push_back("decrement it");    
    vect.push_back("view it");
    vect.push_back("add the wrong item");


    std::cout << "debug check/n";
    Item i("rock", "a rock", 5, 10, 10);
    Item j("paper", "is white", 1, 9, 10);
    Slot s(i, 1 );
    Slot t(j, 5);

    Menu menu(title, menuOptions, vect);
    while(menu.getGameState() != 'e')
    {
        menu.update();
        switch(menu.getGameState())
        {
            case 'a' :

            break;

            case 'b' :
            s.add(i);
            s.item->print();
            break;

            case 'c':
            s.remove(i);
            s.item->print();

            case 'd':
            s.item->print();
            std::cout << "slot: " << "\nStack: " << s.getQuantity() << std::endl;
            break;

            case 'f':   

s.add(j, 1);
s.item->print();

            default :
            break;

        }
    }
}

