#include "TestNTP.h"

#include <iostream>
#include <string>
#include <vector>

TestNTP::TestNTP()
{
    //ctor
}

void TestNTP::testRandom(){
    int size = 0;

    std::cout<<"Set size: ";
    std::cin>>size;

    NodeSet NS = GenNS.genRandomNodeSet(size);

    NS.showNodeSet();

    NearestTrioProblem NTP(NS);
    std::pair<float, float> p1, p2, p3;

    double min_distance = NTP.simpleSolution(p1, p2, p3);

    std::cout<<"The minimal distance is: "<<min_distance<<std::endl
            <<"The minimal trio is <"<<p1.first<<", "<<p1.second<<"> "
            <<"<"<<p2.first<<", "<<p2.second<<"> "
            <<"<"<<p3.first<<", "<<p3.second<<">"<<std::endl;

}

void TestNTP::testFromFile(){
    int option = 0;
    NodeSet NS;

    std::vector<std::string> file = {"data/berlin52.tsp", "data/ch130.tsp", "data/d493.tsp"};
    std::pair<float, float> p1, p2, p3;

    std::cout<<"Select file: \n"
             <<"1. berlin52\n"
             <<"2. ch130\n"
             <<"3. d493\n"
             <<"4. Other file\n"
             <<"Select option: ";
    std::cin>>option;

    if(option != 4) NS = GenNS.genNodeSetFromFile(file[option-1]);
    else{
        std::string filename = "";
        std::cout<<"Introduce filename: ";
        std::cin>>filename;

        filename = "data/" + filename;

        NS = GenNS.genNodeSetFromFile(filename);
    }

    NS.showNodeSet();

    NearestTrioProblem NTP(NS);
    double min_distance = NTP.simpleSolution(p1, p2, p3);

    std::cout<<"The minimal distance is: "<<min_distance<<std::endl
            <<"The minimal trio is <"<<p1.first<<", "<<p1.second<<"> "
            <<"<"<<p2.first<<", "<<p2.second<<"> "
            <<"<"<<p3.first<<", "<<p3.second<<">"<<std::endl;

}
