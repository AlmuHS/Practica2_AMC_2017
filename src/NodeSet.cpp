#include "../include/NodeSet.h"

NodeSet::NodeSet(int size): node_set(size)
{
    //ctor

}

NodeSet::NodeSet(const NodeSet& NS): node_set(NS.node_set)
{

}

void NodeSet::addPair(float x, float y){
    node_set.push_back(std::make_pair(x,y));
}

std::pair<float, float> NodeSet::getPair(int position){
    return node_set[position];
}

int NodeSet::getSize(){
    return node_set.size();
}
