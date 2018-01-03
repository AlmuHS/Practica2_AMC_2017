#include "TestMCP.h"

TestMCP::TestMCP()
{
    //ctor
}

void TestMCP::testAlgorithm(int algorithm){
    int option = 0;
    NodeSet<int> NS;
    std::string filename = "";

    std::vector<std::string> file = {"berlin52.tsp", "ch130.tsp", "ch150.tsp"};

    std::cout<<"Select file: \n"
             <<"1. berlin52\n"
             <<"2. ch130\n"
             <<"3. ch150\n"
             <<"4. Other file\n"
             <<"Select option: ";
    std::cin>>option;

    if(option != 4)
        filename =  file[option-1];
    else
    {
        std::cout<<"Introduce filename: ";
        std::cin>>filename;

        filename = "data/" + filename + "/" + filename;
    }

    GenNodeSet GenNS;

    GenNS.genNodeSetFromFile(NS, filename);
    GenNS.showNodeSet(NS);

    MinimalConectionProblem MCP(NS);

    std::set<edge> solution;
    int distance = MCP.kruskalSolution(solution);

    std::cout<<"The minimal connection tree is: \n";
    for(std::set<edge>::iterator it = solution.begin(); it != solution.end(); it++){
        std::cout<<"<"<<it->a.first<<", "<<it->a.second<<"> - "<<"<"<<it->b.first<<", "<<it->b.second<<"> \n";
    }

    std::cout<<"The minimal distance is "<<distance;
}
