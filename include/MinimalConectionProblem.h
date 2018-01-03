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

#ifndef MINIMALCONECTIONPROBLEM_H
#define MINIMALCONECTIONPROBLEM_H

#include <vector>
#include <utility>
#include <set>

template<typename T0, typename T1 = T0>
using NodeSet = std::vector<std::pair<T0, T1> >;

struct edge{
    std::pair<int, int> a;
    std::pair<int, int> b;

    int distance;
};



class MinimalConectionProblem
{
    private:
        NodeSet<int> _NS;
        std::vector<edge> EdgeSet;
        std::vector<int> distMatrix;

        void genEdgeSet();
        void sortEdgeSet();
        int calculateEuclideanDistance(std::pair<int, int> a, std::pair<int, int> b);

    public:
        MinimalConectionProblem(const NodeSet<int>& NS);
        MinimalConectionProblem(const MinimalConectionProblem& other);

        int primSolution();
        int kruskalSolution(std::set<edge> &solution);
};

#endif // MINIMALCONECTIONPROBLEM_H
