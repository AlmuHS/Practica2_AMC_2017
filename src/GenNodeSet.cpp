#include "GenNodeSet.h"

GenNodeSet::GenNodeSet(int size): NS(size)
{
    //ctor
}

void GenNodeSet::gen_random_nodeset(){
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<float> uni(0,2000); // guaranteed unbiased

    for(int i = 0; i < this->NS.get_size(); i++){
        NS.add_pair(uni(rng), uni(rng));
    }
}
