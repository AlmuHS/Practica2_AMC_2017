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

#include "../include/GenNodeSet.h"
#include <iostream>
#include <algorithm>
#include <random>


GenNodeSet::GenNodeSet()
{
    //ctor
}

GenNodeSet::GenNodeSet(const NodeSet& NS)
{
    _NS = NS;
}

void GenNodeSet::genRandomNodeSet(NodeSet& NS, int size)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<float> uni(0,5000); // guaranteed unbiased

    NS.clear();

    for(int i = 0; i < size; i++)
    {
        NS.push_back(std::make_pair(uni(rng), uni(rng)));
    }


    this->_NS = NS;
}

//Generate a new NodeSet from a datafile
void GenNodeSet::genNodeSetFromFile(NodeSet& NS, const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line = "";
    float x, y;
    int n = 1;

    NS.clear();

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

void GenNodeSet::showNodeSet()
{
    //for(int i = 0; i < NS.size(); i++)
    for(const auto& node: _NS)
    {
        std::cout<<"<"<<node.first<<", "<<node.second<<">\n";
    }
    std::cout<<"\n";
}
