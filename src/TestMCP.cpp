#include "../include/TestMCP.h"

TestMCP::TestMCP()
{
    //ctor
}

void TestMCP::testAlgorithm(const NodeSet& NS, int algorithm){

    MinimalConectionProblem MCP(NS);

    std::set<edge> solution;
    int distance;

    if(algorithm == 2) distance = MCP.kruskalSolution(solution);

    std::cout<<"\n\nThe minimal connection tree is: \n";
    for(std::set<edge>::iterator it = solution.begin(); it != solution.end(); it++){
        std::cout<<"<"<<it->a.first<<", "<<it->a.second<<"> - "<<"<"<<it->b.first<<", "<<it->b.second<<"> \n";
    }

    std::cout<<"The minimal distance is "<<distance;
}
