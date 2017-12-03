#ifndef NEARESTTRIOPROBLEM_H
#define NEARESTTRIOPROBLEM_H

#include <utility>
#include "NodeSet.h"

class NearestTrioProblem
{
private:
    NodeSet _NS;

public:
    NearestTrioProblem(NodeSet NS);

    float calculateDistance(const std::pair<float, float>& p1, const std::pair<float, float>& p2);

    double simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);

    double dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);




};

#endif // NEARESTTRIOPROBLEM_H
