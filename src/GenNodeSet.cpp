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

#include "../include/GenNodeSet.h"
#include <iostream>
#include <algorithm>
#include <random>


GenNodeSet::GenNodeSet()
{
    //ctor
}

template<typename T0>
GenNodeSet::GenNodeSet(NodeSet<T0> NS){
    _NS = NS;
}

void GenNodeSet::genRandomNodeSet(NodeSet<float>& NS, int size)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_real_distribution<float> uni(0,5000); // guaranteed unbiased

    for(int i = 0; i < size; i++)
    {
        NS.push_back(std::make_pair(uni(rng), uni(rng)));
    }


    this->_NS = NS;
}

NodeSet<float> GenNodeSet::xSortNodeSet()
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

NodeSet<float> GenNodeSet::ySortNodeSet()
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
