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


#include "../include/TestMCP.h"

TestMCP::TestMCP()
{
    //ctor
}

void TestMCP::testAlgorithm(const NodeSet& NS, int algorithm, std::string filename){

    MinimalConectionProblem MCP(NS);

    std::multiset<edge> solution;
    std::vector<int> v_solution;
    int distance;

    filename += ".tour";

    if (algorithm == 1) distance = MCP.primSolution(v_solution);
    else if(algorithm == 2) distance = MCP.kruskalSolution(solution);

    std::ofstream fout((char*)filename.c_str());
    fout<<"NAME: "<<filename<<"\n"
        <<"TYPE: TOUR\n"
        <<"DIMENSION: "<<NS.size()<<"\n"
        <<"SOLUTION: "<<distance<<"\n"
        <<"TOUR_SECTION\n";

    std::cout<<"\n\nThe minimal connection tree is: \n";

    if(algorithm == 2){
        for(std::set<edge>::iterator it = solution.begin(); it != solution.end(); it++){
            std::cout<<it->a<<"-"<<it->b<<", ";
            fout<<it->a<<", "<<it->b<<"\n";
        }
        fout<<"EOF";
    }
    else{
        for(std::vector<int>::iterator it = v_solution.begin(); it != v_solution.end(); it++){
            std::cout<<*it<<"-";
            fout<<*it<<", "<<*(it+1)<<"\n";
        }
    }

    std::cout<<"\nThe minimal distance is "<<distance;

}
