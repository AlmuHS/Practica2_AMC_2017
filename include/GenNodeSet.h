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

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

template<typename T0, typename T1 = T0>
using NodeSet = std::vector<std::pair<T0, T1> >;


class GenNodeSet
{

private:
    NodeSet<float> _NS;

public:
    GenNodeSet();

    template<typename T0>
    GenNodeSet(NodeSet<T0> NS){
        _NS = NS;
    }

    //Generate a new NodeSet with random elements
    void genRandomNodeSet(NodeSet<float>& NS, int size);

    //Sort the NodeSet using x coordinate, using ShellSort
    NodeSet<float> xSortNodeSet();

    //Sort the NodeSet using y coordinate, using ShellSort
    NodeSet<float> ySortNodeSet();

    //Generate a new NodeSet from a datafile
    template<typename T0>
    void genNodeSetFromFile(NodeSet<T0>& NS, std::string filename)
    {
        std::ifstream file(filename.c_str());
        std::string line = "";
        T0 x, y;
        int n = 1;

        //Skip file headers
        std::getline(file, line);
        std::getline(file, line);
        std::getline(file, line);
        std::getline(file, line);
        std::getline(file, line);
        std::getline(file, line);

        //Read file line to libe
        while(n != 0)
        {
            file >> n; //line number

            //If linenumber is not null, continues
            if(n != 0)
            {

                //Read data from the line and copy in variables
                file >> x;
                file >> y;

                //Add a new pair with line values
                NS.push_back(std::make_pair(x,y));
            }
        }

        this->_NS = NS;
    }

    //Shows the contents of NodeSet by screen
    template<typename T0>
    void showNodeSet(const NodeSet<T0>& NS)
    {
        for(int i = 0; i < NS.size(); i++)
        {
            std::cout<<"<"<<NS[i].first<<", "<<NS[i].second<<">"<<std::endl;
        }
    }
};

#endif // GENNODESET_H
