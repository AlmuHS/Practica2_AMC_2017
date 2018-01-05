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

#include "../include/NearestTrioProblem.h"
#include "../include/GenNodeSet.h"

#include <cmath>
#include <vector>
#include <limits>
#include <iostream>

NearestTrioProblem::NearestTrioProblem(const NodeSet& NS): _NS(NS)
{

}


float NearestTrioProblem::calculateDistance(const std::pair<float, float>& p1, const std::pair<float, float>& p2)
{
    return sqrt( pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2) );
}


double NearestTrioProblem::calculateMin(const std::pair<float, float>& p1, const std::pair<float, float>& p2, const std::pair<float, float>& p3)
{

    //Calculate three node combs
    float distance1 = calculateDistance(p1, p2);
    float distance2 = calculateDistance(p1, p3);
    float distance3 = calculateDistance(p2, p3);

    //Sum the distance two to two
    double sum_distance1 = distance1 + distance2;
    double sum_distance2 = distance1 + distance3;
    double sum_distance3 = distance2 + distance3;

    //Search the minimal of three sum_distance
    double min = sum_distance1;
    if(sum_distance2 < min)
        min = sum_distance2;
    if(sum_distance3 < min)
        min = sum_distance3;

    return min;
}

double NearestTrioProblem::simpleSolution(NodeSet _NS, std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{

    //Absolute Minimal distance
    double min_distance = std::numeric_limits<double>::infinity();

    for(size_t i = 0; i < _NS.size(); i++) {
        for(size_t j = i+1; j < _NS.size(); j++) {
            for(size_t k = j+1; k < _NS.size(); k++) {

                //Calculate minimal distance in the Trio
                double min = calculateMin(_NS[i], _NS[j], _NS[k]);

                //Update absolute minimal value
                if(min < min_distance) {
                    min_distance = min;
                    p1 = _NS[i];
                    p2 = _NS[j];
                    p3 = _NS[k];
                }

            }//End k for
        }//End j for
    }//End i for

    return min_distance;
}

double NearestTrioProblem::simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{
    return simpleSolution(this->_NS, p1, p2, p3);
}


double NearestTrioProblem::dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{
    GenNodeSet GenNS(_NS);

    //NodeSet sortered
    NodeSet NS = GenNS.xSortNodeSet();

    //NodeSet solution
    NodeSet solution;

    //Call to recursive function
    double min_distance = dcSolution(NS, solution, NS.size());

    //Assign solution to pairs
    p1 = solution[0];
    p2 = solution[1];
    p3 = solution[2];

    return min_distance;
}

double NearestTrioProblem::dcSolution(NodeSet& solution, NodeSet& NSX, int n)
{
    if(n/2 > 3){
        std::pair<float, float> middle = NSX[n/2];
        n /= 2;

        //dcSolution()
    }
    else{


    }

    return 0;

}
