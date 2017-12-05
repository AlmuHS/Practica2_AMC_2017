#include "../include/NodeSet.h"

#include <iostream>
#include <algorithm>

NodeSet::NodeSet()
{
    //ctor
}

NodeSet::NodeSet(const NodeSet& NS): node_set(NS.node_set)
{

}

void NodeSet::addPair(float x, float y)
{
    node_set.push_back(std::make_pair(x,y));
}

std::pair<float, float> NodeSet::getPair(int position)
{
    return node_set[position];
}

int NodeSet::getSize()
{
    return node_set.size();
}

void NodeSet::swapPair(int i, int j)
{
    std::swap(node_set[i], node_set[j]);
}

void NodeSet::showNodeSet()
{
    for(int i = 0; i < node_set.size(); i++)
    {
        std::cout<<"<"<<node_set[i].first<<", "<<node_set[i].second<<">"<<std::endl;
    }
}



