#include "NodeSet.h"

#include <random>

NodeSet::NodeSet(int size): node_set(size)
{
    //ctor

}

NodeSet::NodeSet(const std::vector<std::pair<float, float> > &node_set){
    this->node_set = node_set;
}

void NodeSet::gen_random_nodeset(){
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<float> uni(0,2000); // guaranteed unbiased

    for(int i = 0; i < this->node_set.size(); i++){
        this->node_set[i] = std::make_pair(uni(rng), uni(rng));
    }

    node_set = this->node_set;
}

void NodeSet::add_pair(float x, float y){
    node_set.push_back(std::make_pair(x,y));
}

void NodeSet::get_nodeset(std::vector<std::pair<float, float> >& node_set){
    node_set = this->node_set;
}
