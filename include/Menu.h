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

#ifndef MENU_H
#define MENU_H

#include "GenNodeSet.h"
#include "TestAlgorithms.h"


#include <string>

class Menu
{
    public:
        Menu();
        void clear();
        void MainMenu();
        void NTPMenu();
        void MCPMenu();
        NodeSet fileMenu(std::string& filename);

    private:
        TestAlgorithms Test;
        NodeSet NS;
        GenNodeSet GenNS;

};

#endif // MENU_H
