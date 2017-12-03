#include "../include/Menu.h"
#include "../include/GenNodeSet.h"
#include "../include/NearestTrioProblem.h"

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

        GenNodeSet generator(size);
        NodeSet NS = generator.genRandomNodeSet();
        NS.showNodeSet();

        NearestTrioProblem NTP(NS);
        std::pair<float, float> p1, p2, p3;

        double mindistance = NTP.simpleSolution(p1, p2, p3);

        std::cout<<"The minimal distance is: "<<mindistance<<std::endl
                <<"The minimal trio is <"<<p1.first<<", "<<p1.second<<"> "
                <<"<"<<p2.first<<", "<<p2.second<<"> "
                <<"<"<<p3.first<<", "<<p3.second<<">"<<std::endl;


    };

}
