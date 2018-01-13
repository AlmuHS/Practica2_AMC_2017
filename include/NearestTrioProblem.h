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

#ifndef NEARESTTRIOPROBLEM_H
#define NEARESTTRIOPROBLEM_H

#include <utility>
#include <vector>

//using NodeSet = std::vector<std::pair<float, float> >;

using NodeSet = std::vector<std::pair<float, float> >;

class NearestTrioProblem
{
private:
    NodeSet _NS;
    std::pair<float, float> p1, p2, p3;
    double min_distance;

    //Calculate the distance between two nodes
    float calculateDistance(const std::pair<float, float>& p1, const std::pair<float, float>& p2);

    //Calculate the minimal path to connect 3 nodes
    double calculateMin(const std::pair<float, float>& p1, const std::pair<float, float>& p2, const std::pair<float, float>& p3);

public:
    NearestTrioProblem(const NodeSet& NS);

    //Exhaustive algorithm
    double simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);

    //Auxiliar method for D&C algorithm, to search center points
    double center(const NodeSet& left, const NodeSet& right, double frontier, std::pair<float, float>& pivot);

    //Auxiliar method for D&C algorithm, to do exhaustive search over center pointa
    void centerExhaustiveSearch(NodeSet& aux1, NodeSet& aux2, std::pair<float, float>& pivot, double& dmin);

    //Call to dcSolution recursive function
    double dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);

    //Divide and Conquer recursive method
    double dcSolution(NodeSet& NS);

};

#endif // NEARESTTRIOPROBLEM_H
