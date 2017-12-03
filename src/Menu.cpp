#include "../include/Menu.h"
#include "../include/TestNTP.h"

#include <iostream>

Menu::Menu()
{
    //ctor
}

void Menu::MainMenu()
{
    int option = 0;

    std::cout<<"Complex Algorithms Study\n"
             <<"----------------------------\n"
             <<"1. Test Nearest Trio Problem\n"
             <<"Select option: ";
    std::cin>>option;

    switch(option)
    {
    case 1:
        NTPMenu();
        break;

    }

}

void Menu::NTPMenu()
{
    int option1 = 0, option2 = 0;
    int size;

    std::cout<<"1. Test Random set\n"
             <<"2. Test from File\n"
             <<"Select option: ";
    std::cin>>option1;


    std::cout<<"Select algorithm: \n"
             <<"1. Simple \n"
             <<"2. Divide & Conquer\n"
             <<"Select option: ";
    std::cin>>option2;

    switch(option1)
    {
    case 1:
        std::cout<<"Set size: ";
        std::cin>>size;

        TestNTP TNTP(size);
        TNTP.testRandom();


    };

}
