#include "../include/GenNodeSet.h"
#include <iostream>
#include <fstream>

GenNodeSet::GenNodeSet()
{
    //ctor
}

NodeSet GenNodeSet::genRandomNodeSet(int size)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<float> uni(0,5000); // guaranteed unbiased

    for(int i = 0; i < size; i++)
    {
        _NS.addPair(uni(rng), uni(rng));
    }

    return _NS;
}

NodeSet GenNodeSet::xSortNodeSet(){

    for(int h = _NS.getSize() / 2; h > 0; h /= 2)
    {

        for(int i = h; i < _NS.getSize(); i++)
        {
            int j = i;
            std::pair<float, float> elem = _NS.getPair(i);

            while(j >= h && elem.first < _NS.getPair(j-h).first)
            {
                _NS.swapPair(j, j-h);
                j -= h;
            }

            _NS.getPair(j) = elem;
        }
    }
    return _NS;
}

NodeSet GenNodeSet::genNodeSetFromFile(std::string filename){
    std::ifstream file(filename.c_str());
    std::string line = "";
    float x, y;
    int n = 1;

    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);

    while(n != 0){
        file >> n;
        if(n != 0){
            file >> x;
            file >> y;
            _NS.addPair(x, y);
        }
    }
    return _NS;
}
