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
#include <limits>
#include <chrono>

//overloaded operator, needed to std::set and std::sort
bool operator<(const edge& e1, const edge& e2)
{
    return(e1.distance < e2.distance);
}

MinimalConectionProblem::MinimalConectionProblem(const NodeSet& NS): _NS(NS), distMatrix(NS.size(), std::vector<int>(NS.size(), std::numeric_limits<int>::infinity()))
{
    //ctor

}

MinimalConectionProblem::MinimalConectionProblem(const MinimalConectionProblem& other)
{
    //copy ctor
    *this = other;
}


int MinimalConectionProblem::calculateEuclideanDistance(const std::pair<float, float>& a, const std::pair<float, float>& b)
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

void MinimalConectionProblem::initializeDistMatrix()
{
    std::vector<std::vector<int> >::iterator itmatrix = distMatrix.begin();

    for(const auto& i: _NS)
    {
        std::vector<int>::iterator itrow = itmatrix->begin();

        for(const auto& j: _NS)
        {
            *itrow = calculateEuclideanDistance(i, j);
            itrow++;
        }
        itmatrix++;
    }
}


int MinimalConectionProblem::primSolution(std::multiset<edge>& solution)
{
    std::chrono::steady_clock::time_point t_start, t_end;

    t_start = std::chrono::steady_clock::now();


    initializeDistMatrix();

    //Variables to select row and column in distance matrix
    int x, y = 0;

    x = y;

    //Solution nodes set
    std::set<int> B;

    //Node set (inverse to B)
    std::set<int> NS;

    //Path distance
    int distance = 0;

    //Initialize node set
    for(unsigned int i = 0; i < _NS.size(); i++)
    {
        NS.insert(i);
    }

    //Sort Edgeset
    std::multiset<edge> sort_set;


    while(!NS.empty())
    {

        //Add new node to node set
        B.insert(y);

        //Travel to new node's row in distance matrix
        x = y;

        //Add edges from new node to sorted edge set, using its distance matrix row
        int j = 0;
        for(const auto& edge_distance: distMatrix[x])
        {
            if(edge_distance > 0 && B.find(j) == B.end()) sort_set.insert(edge{x, j, edge_distance});
            j++;
        }

        //Get minimal edge
        std::multiset<edge>::iterator itsort = sort_set.begin();

        //if the minimal edge point to B set, search next minimal and remove invalid edge
        while(B.find(itsort->b) != B.end()){
            sort_set.erase(*itsort);
            itsort++;
        }

        std::cout<<x<<"-"<<itsort->b<<"-"<<distance<<std::endl;
        distance += itsort->distance;
        y = itsort->b;

        //Add edge to solution set
        solution.insert(edge{x, y, distance});

        //Delete connected nodes
        NS.erase(x);
        NS.erase(y);

        //Delete edge from sorted edge set
        sort_set.erase(*itsort);

    }

    t_end = std::chrono::steady_clock::now();

    time = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();

    return distance;
}

int MinimalConectionProblem::kruskalSolution(std::multiset<edge>& solution)
{
    std::chrono::steady_clock::time_point t_start, t_end;

    int distance = 0;
    std::vector<std::set<int> > set_collection;

    t_start = std::chrono::steady_clock::now();

    //Generate EdgeSet
    genEdgeSet();

    //Transform Edgeset in a sorted heap using distance
    std::make_heap(EdgeSet.begin(), EdgeSet.end());
    std::sort_heap(EdgeSet.begin(), EdgeSet.end());

    //auxiliar nodeset with nodes' numeric names
    std::set<int> NS;

    //Initialize set vector and node set
    for(unsigned int i = 0; i < _NS.size(); i++)
    {
        std::set<int> new_set;
        new_set.insert(i);
        set_collection.push_back(new_set);
        NS.insert(i);
    }

    //execute algorithm
    std::vector<edge>::iterator itedge = EdgeSet.begin();
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
                if(U == -1 && itsc->find(itedge->a) != itsc->end())
                    U = i;
                if(V == -1 && itsc->find(itedge->b) != itsc->end())
                    V = i;
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
            NS.erase(itedge->a);
            NS.erase(itedge->b);

            //Merge set
            std::set<int>::iterator itset = itv->begin();
            while(!itv->empty())
            {
                itu->insert(*itset);
                itset = itv->erase(itset);
            }

            //Add edge to solution set
            solution.insert(*itedge);
            distance += itedge->distance;
            std::cout<<itedge->a<<"-"<<itedge->b<<" ->\t"<<itedge->distance<<std::endl;
        }
        itedge++;
    }

    t_end = std::chrono::steady_clock::now();

    time = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();

    return distance;

}


double MinimalConectionProblem::getTime(){
    return time;
}
