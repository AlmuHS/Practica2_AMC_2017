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
bool operator<(const edge& e1, const edge& e2){
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
    for(NodeSet::iterator it = _NS.begin(); it != _NS.end(); it++)
    {
        for(NodeSet::iterator it2 = it+1; it2 != _NS.end(); it2++)
        {
            EdgeSet.push_back( edge{*it, *it2, calculateEuclideanDistance(*it, *it2) } );
        }
    }
}

int MinimalConectionProblem::primSolution()
{
    return 0;
}

int MinimalConectionProblem::kruskalSolution(std::set<edge>& solution)
{
    int connected = 0;
    int distance = 0;
    std::vector<std::set<std::pair<float, float> > > set_collection;

    //Generate EdgeSet
    genEdgeSet();

    //Sort Edgeset using distance
    std::sort(EdgeSet.begin(), EdgeSet.end());

    //Initialize set vector
    for(NodeSet::iterator it = _NS.begin(); it != _NS.end(); it++){
        std::set<std::pair<float, float> > new_set;
        new_set.insert(*it);
        set_collection.push_back(new_set);
    }

    //execute algorithm
    std::vector<edge>::iterator it = EdgeSet.begin();
    while(connected < _NS.size()){
        int U, V;
        U = V = -1;

        //Search edge in set vector
        int i = 0;
        while(U == -1 || V == -1){
            if(U == -1){
                if(set_collection[i].find(it->a) != set_collection[i].end()) U = i;
            }
            if(V == -1){
                if(set_collection[i].find(it->b) != set_collection[i].end()) V = i;
            }
            i++;
        }

        //If both set are different, add edge to solution set
        if(set_collection[U] != set_collection[V]){
            connected += 2;

            //Merge set
            std::set<std::pair<float, float> >::iterator itsc = set_collection[V].begin();
            while(!set_collection[V].empty()){
                set_collection[U].insert(*itsc);
                itsc = set_collection[V].erase(itsc);
            }

            //Add edge to solution set
            solution.insert(*it);
            distance += it->distance;
            std::cout<<"<"<<it->a.first<<","<<it->a.second<<"> <"<<it->b.first<<","<<it->b.second<<"> - "<<distance<<std::endl;
        }
        it++;
    }

    return distance;

}
