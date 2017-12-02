#ifndef NEARESTTRIOPROBLEM_H
#define NEARESTTRIOPROBLEM_H

#include <utility>
#include "NodeSet.h"

class NearestTrioProblem
{
    public:
        NearestTrioProblem(NodeSet NS);

        float calculateDistance(std::pair<float, float> p1, std::pair<float, float> p2);

        double simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);



    protected:

        NodeSet _NS;

};

#endif // NEARESTTRIOPROBLEM_H
