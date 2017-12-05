#ifndef NEARESTTRIOPROBLEM_H
#define NEARESTTRIOPROBLEM_H

#include <utility>
#include <vector>

using NodeSet = std::vector<std::pair<float, float> >;


class NearestTrioProblem
{
private:
    NodeSet _NS;

public:
    NearestTrioProblem(NodeSet NS);

    float calculateDistance(const std::pair<float, float>& p1, const std::pair<float, float>& p2);

    double simpleSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);

    double dcSolution(std::pair<float, float>& p1, std::pair<float, float>& p2, std::pair<float, float>& p3);

    void divide(const NodeSet &NS, NodeSet &left, NodeSet &right);

    double dcSolution(NodeSet& solution, NodeSet &origin, double &min_distance);




};

#endif // NEARESTTRIOPROBLEM_H
