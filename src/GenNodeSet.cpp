#include "../include/GenNodeSet.h"
#include <iostream>
#include <fstream>
#include <algorithm>

GenNodeSet::GenNodeSet()
{
    //ctor
}

GenNodeSet::GenNodeSet(NodeSet NS): _NS(NS){
}

NodeSet GenNodeSet::genRandomNodeSet(int size)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<float> uni(0,5000); // guaranteed unbiased

    //Remove all existing elements
    _NS.clear();

    for(int i = 0; i < size; i++)
    {
        _NS.push_back(std::make_pair(uni(rng), uni(rng)));
    }


    return _NS;
}

NodeSet GenNodeSet::xSortNodeSet()
{

    for(int h = _NS.size() / 2; h > 0; h /= 2)
    {

        for(int i = h; i < _NS.size(); i++)
        {
            int j = i;
            std::pair<float, float> elem = _NS[i];

            while(j >= h && elem.first < _NS[j-h].first)
            {
                std::swap(_NS[j], _NS[j-h]);
                j -= h;
            }

            _NS[j] = elem;
        }
    }
    return _NS;
}

NodeSet GenNodeSet::ySortNodeSet()
{

    for(int h = _NS.size() / 2; h > 0; h /= 2)
    {

        for(int i = h; i < _NS.size(); i++)
        {
            int j = i;
            std::pair<float, float> elem = _NS[i];

            while(j >= h && elem.second < _NS[j-h].second)
            {
                std::swap(_NS[j], _NS[j-h]);
                j -= h;
            }

            _NS[j] = elem;
        }
    }
    return _NS;
}

NodeSet GenNodeSet::genNodeSetFromFile(std::string filename)
{
    std::ifstream file(filename.c_str());
    std::string line = "";
    float x, y;
    int n = 1;

    //Remove all existing elements
    _NS.clear();

    //Skip file headers
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);

    //Read file line to libe
    while(n != 0)
    {
        file >> n; //line number

        //If linenumber is not null, continues
        if(n != 0)
        {

            //Read data from the line and copy in variables
            file >> x;
            file >> y;

            //Add a new pair with line values
            _NS.push_back(std::make_pair(x,y));
        }
    }
    return _NS;
}


void GenNodeSet::showNodeSet()
{
    for(int i = 0; i < _NS.size(); i++)
    {
        std::cout<<"<"<<_NS[i].first<<", "<<_NS[i].second<<">"<<std::endl;
    }
}
