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

void TestNTP::testFromFile(const NodeSet &NS, int algorithm)
{
   NearestTrioProblem NTP(NS);

    double min_distance;
    std::pair<float, float> p1, p2, p3;

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
