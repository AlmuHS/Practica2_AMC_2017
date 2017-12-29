#ifndef MINIMALCONECTIONPROBLEM_H
#define MINIMALCONECTIONPROBLEM_H

#include <vector>
#include <utility>

template<typename T0, typename T1 = T0>
using NodeSet = std::vector<std::pair<T0, T1> >;

class MinimalConectionProblem
{
    private:
        NodeSet<int> _NS;

    public:
        MinimalConectionProblem();
        MinimalConectionProblem(const MinimalConectionProblem& other);

        int calculateEuclideanDistance(std::pair<int, int> a, std::pair<int, int> b);

        int PrimSolution();
        int KruskalSolution();
};

#endif // MINIMALCONECTIONPROBLEM_H
