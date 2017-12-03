#include "TestNTP.h"

#include <iostream>

TestNTP::TestNTP()
{
    //ctor
}

void TestNTP::testRandom(int size){
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

void TestNTP::testFromFile(std::string filename){

}
