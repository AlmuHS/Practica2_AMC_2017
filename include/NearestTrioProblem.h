#ifndef NEARESTTRIOPROBLEM_H
#define NEARESTTRIOPROBLEM_H

#include <utility>
#include "NodeSet.h"

class NearestTrioProblem
{
    public:
        NearestTrioProblem(NodeSet NS_);

        float Calculate_Distance(std::pair<float, float> p1, std::pair<float, float> p2);

        double SimpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);



    protected:

        NodeSet NS;

};

#endif // NEARESTTRIOPROBLEM_H
