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

#include "MinimalConectionProblem.h"

#include <cmath>

MinimalConectionProblem::MinimalConectionProblem(const NodeSet<int>& NS): _NS(NS)
{
    //ctor
}

MinimalConectionProblem::MinimalConectionProblem(const MinimalConectionProblem& other)
{
    //copy ctor
    *this = other;
}

int MinimalConectionProblem::calculateEuclideanDistance(std::pair<int, int> a, std::pair<int, int> b)
{
    int xd = a.first - b.first;
    int yd = a.second - b.second;

    return rint(sqrt(xd*xd + yd*yd));
}

void MinimalConectionProblem::genEdgeSet()
{
    for(int i = 0; i < _NS.size(); i++)
    {
        for(int j = i + 1; j < _NS.size(); j++)
        {
            EdgeSet.push_back( edge{i, j, calculateEuclideanDistance(_NS[i], _NS[j]) } );
        }
    }
}


int MinimalConectionProblem::primSolution()
{

}

int MinimalConectionProblem::kruskalSolution()
{

}
