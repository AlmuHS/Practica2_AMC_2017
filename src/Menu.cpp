/*Copyright 2017 Almudena Garcia Jurado-Centurion

This file is part of Practica2_AMC.

Practica2_AMC is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Practica2_AMC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Practica2_AMC.  If not, see <http://www.gnu.org/licenses/>.*/

#include "../include/Menu.h"
#include "../include/TestNTP.h"
#include "../include/TestMCP.h"

#include <iostream>
#include <limits>

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
                 <<"2. Test Minimal Connection Problem\n"
                 <<"Select option: ";
        std::cin>>option;

        clear();

        switch(option)
        {
        case 0:
            exit(0);
            break;

        case 1:
            NTPMenu();
            break;

        case 2:
            MCPMenu();
            break;

        }


        std::cout<<"\n\nPress ENTER to continue\n";

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin.ignore();

        clear();
    }
    while(option != 0);

}

void Menu::NTPMenu()
{
    int option1 = 0, option2 = 0;
    TestNTP TNTP;

    std::cout<<"Nearest Trio Problem\n"
             <<"----------------------\n"
             <<"Select algorithm: \n"
             <<"1. Simple \n"
             <<"2. Divide & Conquer\n"
             <<"Select option: ";
    std::cin>>option1;

    clear();

    std::cout<<"Nearest Trio Problem\n"
             <<"----------------------\n"
             <<"1. Test Random set\n"
             <<"2. Test from File\n"
             <<"Select option: ";
    std::cin>>option2;

    clear();

    switch(option2)
    {
    case 1:

        TNTP.testRandom(option1);
        break;

    case 2:

        TNTP.testFromFile(option1);
        break;

    };
}

void Menu::MCPMenu(){
    int option;

    TestMCP TMCP;

    std::cout<<"Minimal Connection Problem\n"
             <<"-----------------------------\n"
             <<"Select algorithm: \n"
             <<"1. Prim\n"
             <<"2. Kruskal\n"
             <<"Select option: ";
    std::cin>>option;

    clear();

    TMCP.testAlgorithm(option);
}
