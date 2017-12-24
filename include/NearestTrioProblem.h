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

using NodeSet = std::vector<std::pair<float, float> >;


class NearestTrioProblem
{
private:
    NodeSet _NS;

public:
    NearestTrioProblem(NodeSet NS);

    float calculateDistance(const std::pair<float, float>& p1, const std::pair<float, float>& p2);

    double calculateMin(const std::pair<float, float>& p1, const std::pair<float, float>& p2, const std::pair<float, float>& p3);

    double stripClosest(NodeSet strip, double d);

    double simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);

    double simpleSolution(NodeSet _NS, std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);

    double dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);

    double dcSolution(NodeSet& solution, NodeSet& NSX, NodeSet& NSY, int n);

};

#endif // NEARESTTRIOPROBLEM_H
