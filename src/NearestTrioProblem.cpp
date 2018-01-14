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

#include <cmath>
#include <limits>
#include <iostream>
#include <algorithm>

//Overloaded operator, needed to std::sort
bool operator<(const std::pair<float, float> &p1, const std::pair<float, float> &p2)
{
    return(p1.first < p2.first);
}


NearestTrioProblem::NearestTrioProblem(const NodeSet& NS): _NS(NS)
{
    min_distance = std::numeric_limits<double>::max();
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

double NearestTrioProblem::simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{

    //Absolute Minimal distance
    double min_distance = std::numeric_limits<double>::infinity();

    //for(size_t i = 0; i < _NS.size(); i++) {
    for(NodeSet::const_iterator it = _NS.cbegin(); it != _NS.cend(); it++)
    {
        for(NodeSet::const_iterator it2 = it+1; it2 != _NS.cend(); it2++)
        {
            for(NodeSet::const_iterator it3 = it2+1; it3 != _NS.cend(); it3++)
            {
                //Calculate minimal distance in the Trio
                double min = calculateMin(*it, *it2, *it3);

                //Update absolute minimal value
                if(min < min_distance)
                {
                    min_distance = min;
                    p1 =  *it;
                    p2 = *it2;
                    p3 = *it3;
                }

            }//End k for
        }//End j for
    }//End i for

    return min_distance;
}

//Auxiliar method for D&C algorithm, to search center points
double NearestTrioProblem::center(const NodeSet& left, const NodeSet& right, const double& frontier, const std::pair<float, float>& pivot)
{
    NodeSet SubLeft, SubRight;

    for(const auto& pleft: left)
    {
        if(pleft.first >= (pivot.first - frontier))
        {
            SubLeft.push_back(pleft);
        }
    }

    for(const auto& pright: right)
    {
        if(pright.first <= (pivot.first + frontier))
        {
            SubRight.push_back(pright);
        }
    }

    double dmin = min_distance;

    centerExhaustiveSearch(SubLeft, SubRight, dmin);
    centerExhaustiveSearch(SubRight, SubLeft, dmin);

    min_distance = dmin;

    return dmin;
}

//Auxiliar method for D&C algorithm, to do exhaustive search over center pointa
void NearestTrioProblem::centerExhaustiveSearch(const NodeSet& aux1, const NodeSet& aux2, double& dmin)
{

    for(const auto& p1: aux1)
    {
        for(const auto& p2: aux1)
        {
            if(p1 != p2)
            {
                for(const auto& p3: aux2)
                {
                    double distance = calculateMin(p1, p2, p3);
                    if(distance < dmin)
                    {
                        this->p1 = p1;
                        this->p2 = p2;
                        this->p3 = p3;

                        dmin = distance;

                    }
                }

            }
        }
    }
}

double NearestTrioProblem::dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3)
{

    std::sort(_NS.begin(), _NS.end());

    double min_distance = dcSolution(_NS);

    p1 = this->p1;
    p2 = this->p2;
    p3 = this->p3;

    return min_distance;
}


double NearestTrioProblem::dcSolution(const NodeSet& NS)
{
    if(NS.size() >= 3)
    {
        NodeSet::const_iterator it_pivot = NS.begin() + (NS.size()/2);
        std::pair<float, float> pivot = *it_pivot;

        NodeSet left(NS.begin(), it_pivot-1);
        double dMinLeft = dcSolution(left);

        NodeSet right(it_pivot, NS.end());
        double dMinRight = dcSolution(right);

        return center(left, right, std::min(dMinLeft, dMinRight), pivot);
    }
    else return std::numeric_limits<double>::max();
}
