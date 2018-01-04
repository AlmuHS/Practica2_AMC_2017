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

//overloaded operator, needed to std::set
bool operator<(const edge& e1, const edge& e2){
    return(e1.distance < e2.distance);
}


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
            EdgeSet.push_back( edge{_NS[i], _NS[j], calculateEuclideanDistance(_NS[i], _NS[j]) } );
        }
    }
}

void MinimalConectionProblem::sortEdgeSet(){
    for(int h = EdgeSet.size() / 2; h > 0; h /= 2)
    {

        for(int i = h; i < EdgeSet.size(); i++)
        {
            int j = i;
            struct edge elem = EdgeSet[i];

            while(j >= h && elem.distance < EdgeSet[j-h].distance)
            {
                std::swap(EdgeSet[j], EdgeSet[j-h]);
                j -= h;
            }

            EdgeSet[j] = elem;
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
    std::vector<std::set<std::pair<int, int> > > set_collection;

    //Generate EdgeSet
    genEdgeSet();

    //Sort Edgeset using distance
    sortEdgeSet();

    //Initialize vector of set
    for(NodeSet<int>::iterator it = _NS.begin(); it != _NS.end(); it++){
        std::set<std::pair<int, int> > new_set;
        new_set.emplace(*it);
        set_collection.push_back(new_set);
    }

    //execute algorithm
    std::vector<edge>::iterator it = EdgeSet.begin();
    while(connected < _NS.size()){
        int U, V;
        U = V = -1;

        //Search edge in set's vector
        int i = 0;
        while(U != -1 && V != -1){
            if(U != -1){
                if(set_collection[i].find(it->a) != set_collection[i].end()) U = i;
            }
            if(V != -1){
                if(set_collection[i].find(it->b) != set_collection[i].end()) V = i;
            }
            i++;
        }

        if(set_collection[U] != set_collection[V]){
            connected++;
            it++;

            //Merge elements
            std::set<std::pair<int, int> >::iterator itsc = set_collection[V].begin();
            while(!set_collection[V].empty()){
                set_collection[U].insert(*itsc);
                itsc = set_collection[V].erase(itsc);
            }
            set_collection.erase(set_collection.begin()+V);

            solution.insert(*it);
            distance+= it->distance;
        }

    }

    return distance;

}