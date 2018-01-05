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

#include "../include/TestNTP.h"

#include <iostream>
#include <string>
#include <vector>

TestNTP::TestNTP()
{
    //ctor
}

void TestNTP::testRandom(int algorithm)
{
    int size;

    std::cout<<"Set size: ";
    std::cin>>size;

    GenNodeSet GenNS;

    NodeSet NS;
    GenNS.genRandomNodeSet(NS, size);

    GenNS.showNodeSet(NS);

    NearestTrioProblem NTP(NS);
    std::pair<float, float> p1, p2, p3;

    double min_distance;

    if(algorithm == 1)
        min_distance = NTP.simpleSolution(p1, p2, p3);
    else min_distance = NTP.dcSolution(p1, p2, p3);

    std::cout<<"The minimal distance is: "<<min_distance<<std::endl
             <<"The minimal trio is <"<<p1.first<<", "<<p1.second<<"> "
             <<"<"<<p2.first<<", "<<p2.second<<"> "
             <<"<"<<p3.first<<", "<<p3.second<<">"<<std::endl;

}

void TestNTP::testFromFile(int algorithm)
{
    int option = 0;
    NodeSet NS;
    std::string filename = "";

    std::vector<std::string> file = {"data/berlin52.tsp/berlin52.tsp", "data/ch130.tsp/ch130.tsp", "data/ch150.tsp/ch150.tsp"};
    std::pair<float, float> p1, p2, p3;

    std::cout<<"Select file: \n"
             <<"1. berlin52\n"
             <<"2. ch130\n"
             <<"3. ch150\n"
             <<"4. Other file\n"
             <<"Select option: ";
    std::cin>>option;

    if(option != 4)
        filename =  file[option-1];
    else
    {
        std::cout<<"Introduce filename: ";
        std::cin>>filename;

        filename = "data/" + filename + "/" + filename;
    }

    GenNodeSet GenNS;

    GenNS.genNodeSetFromFile(NS, filename);
    GenNS.showNodeSet(NS);

   NearestTrioProblem NTP(NS);

    double min_distance;

    if(algorithm == 1)
        min_distance = NTP.simpleSolution(p1, p2, p3);
    else{
        min_distance = NTP.dcSolution(p1, p2, p3);
    }


    std::cout<<"The minimal distance is: "<<min_distance<<std::endl
             <<"The minimal trio is <"<<p1.first<<", "<<p1.second<<"> "
             <<"<"<<p2.first<<", "<<p2.second<<"> "
             <<"<"<<p3.first<<", "<<p3.second<<">"<<std::endl;

}
