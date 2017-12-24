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

#ifndef GENNODESET_H
#define GENNODESET_H

#include <random>
#include <string>

using NodeSet = std::vector<std::pair<float, float> >;

class GenNodeSet
{

private:
    NodeSet _NS;

public:
    GenNodeSet();
    GenNodeSet(NodeSet NS);

    //Generate a new NodeSet with random elements
    NodeSet genRandomNodeSet(int size);

    //Sort the NodeSet using x coordinate, using ShellSort
    NodeSet xSortNodeSet();

    //Sort the NodeSet using y coordinate, using ShellSort
    NodeSet ySortNodeSet();

    //Generate a new NodeSet from a datafile
    NodeSet genNodeSetFromFile(std::string filename);

    //Shows the contents of NodeSet by screen
    void showNodeSet();
};

#endif // GENNODESET_H
