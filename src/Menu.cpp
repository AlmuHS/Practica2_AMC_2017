#include "../include/Menu.h"
#include "../include/TestNTP.h"

#include <iostream>

Menu::Menu()
{
    //ctor
}

#if defined __unix__ || defined __linux__

void Menu::clear()
{
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

#elif defined _WIN32 || defined _WIN64
#include <windows.h>

void Menu::clear()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, &csbi);

    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

    SetConsoleCursorPosition(hStdOut, coord);
}

#endif


void Menu::MainMenu()
{
    int option = 1;

    do
    {


        std::cout<<"Complex Algorithms Study\n"
                 <<"----------------------------\n"
                 <<"0. Exit\n"
                 <<"1. Test Nearest Trio Problem\n"
                 <<"Select option: ";
        std::cin>>option;

        clear();

        switch(option)
        {
        case 0:
            exit(0);

        case 1:
            NTPMenu();
            break;

        }

        std::cout<<"\n\nPress ENTER to continue";
        //std::cin.clear();
        //std::cin.ignore();
        //std::cin.ignore();

        std::cin.seekg(std::ios_base::end);
        std::cin.clear();
        std::cin.ignore();
        clear();
    }
    while(option != 0);

}

void Menu::NTPMenu()
{
    int option1 = 0, option2 = 0;
    int size;

    std::cout<<"Nearest Trio Problem\n"
             <<"----------------------\n"
             <<"1. Test Random set\n"
             <<"2. Test from File\n"
             <<"Select option: ";
    std::cin>>option1;

    clear();

    std::cout<<"Nearest Trio Problem\n"
             <<"----------------------\n"
             <<"Select algorithm: \n"
             <<"1. Simple \n"
             <<"2. Divide & Conquer\n"
             <<"Select option: ";
    std::cin>>option2;

    switch(option1)
    {
    case 1:
        std::cout<<"Set size: ";
        std::cin>>size;

        clear();

        TestNTP TNTP;
        TNTP.testRandom(size);
    };
}
