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

using NodeSet = std::vector<std::pair<float, float> >;

struct edge{
    int a;
    int b;

    int distance;
};

class MinimalConectionProblem
{
    private:
        NodeSet _NS;
        std::vector<edge> EdgeSet;
        std::vector<std::vector<int> > distMatrix;

        void genEdgeSet();
        int calculateEuclideanDistance(const std::pair<float, float>& a, const std::pair<float, float>& b);
        void initializeDistMatrix();

    public:
        MinimalConectionProblem(const NodeSet& NS);
        MinimalConectionProblem(const MinimalConectionProblem& other);

        int primSolution(std::multiset<edge> &solution);
        int kruskalSolution(std::multiset<edge> &solution);
};

#endif // MINIMALCONECTIONPROBLEM_H
