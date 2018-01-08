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

#include "../include/MinimalConectionProblem.h"

#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>

//overloaded operator, needed to std::set and std::sort
bool operator<(const edge& e1, const edge& e2)
{
    return(e1.distance < e2.distance);
}

MinimalConectionProblem::MinimalConectionProblem(const NodeSet& NS): _NS(NS)
{
    //ctor
}

MinimalConectionProblem::MinimalConectionProblem(const MinimalConectionProblem& other)
{
    //copy ctor
    *this = other;
}

int MinimalConectionProblem::calculateEuclideanDistance(std::pair<float, float> a, std::pair<float, float> b)
{
    float xd = a.first - b.first;
    float yd = a.second - b.second;

    return rint(sqrt(xd*xd + yd*yd));
}

void MinimalConectionProblem::genEdgeSet()
{
    int i, j;
    i = 0;
    j = 1;

    for(NodeSet::iterator it = _NS.begin(); it != _NS.end(); it++)
    {
        j = i+1;
        for(NodeSet::iterator it2 = it+1; it2 != _NS.end(); it2++)
        {
            EdgeSet.push_back( edge{i, j, calculateEuclideanDistance(*it, *it2) } );
            j++;
        }
        i++;
    }
}

int MinimalConectionProblem::primSolution()
{
    return 0;
}

int MinimalConectionProblem::kruskalSolution(std::multiset<edge>& solution)
{
    int distance = 0;
    std::vector<std::set<int> > set_collection;

    //Generate EdgeSet
    genEdgeSet();

    //Transform Edgeset in a sorted heap using distance
    std::make_heap(EdgeSet.begin(), EdgeSet.end());
    std::sort_heap(EdgeSet.begin(), EdgeSet.end());

    //auxiliar nodeset to execute algorithm faster
    std::set<int> NS;

    //Initialize set vector and node set
    for(int i = 0; i < _NS.size(); i++)
    {
        std::set<int> new_set;
        new_set.insert(i);
        set_collection.push_back(new_set);
        NS.insert(i);
    }

    //execute algorithm
    std::vector<edge>::iterator it = EdgeSet.begin();
    while(!NS.empty())
    {
        int U, V;
        U = V = -1;

        //Search edge in set vector
        int i = 0;
        std::vector<std::set<int> >::iterator itsc = set_collection.begin();
        while(U == -1 || V == -1)
        {
            if(!itsc->empty())
            {
                if(U == -1 && itsc->find(it->a) != itsc->end()) U = i;
                if(V == -1 && itsc->find(it->b) != itsc->end()) V = i;
            }
            i++;
            itsc++;
        }

        std::vector<std::set<int> >::iterator itu = set_collection.begin() + U;
        std::vector<std::set<int> >::iterator itv = set_collection.begin() + V;

        //If both set are different, add edge to solution set
        if(U != V && *itu != *itv)
        {
            //Delete connected nodes
            NS.erase(it->a);
            NS.erase(it->b);

            //Merge set
            std::set<int>::iterator itset = itv->begin();
            while(!itv->empty())
            {
                itu->insert(*itset);
                itset = itv->erase(itset);
            }

            //Add edge to solution set
            solution.insert(*it);
            distance += it->distance;
            std::cout<<it->a<<"-"<<it->b<<" ->\t"<<it->distance<<std::endl;
        }
        it++;
    }

    return distance;

}
