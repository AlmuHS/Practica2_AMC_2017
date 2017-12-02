#include "../include/NodeSet.h"

NodeSet::NodeSet(int size): node_set(size)
{
    //ctor

}

NodeSet::NodeSet(const NodeSet& NS){
    this->node_set = NS.node_set;
}

void NodeSet::add_pair(float x, float y){
    node_set.push_back(std::make_pair(x,y));
}

std::pair<float, float> NodeSet::get_pair(int position){
    return node_set[position];
}

int NodeSet::get_size(){
    return node_set.size();
}
