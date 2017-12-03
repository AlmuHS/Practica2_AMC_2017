#include "TestNTP.h"

#include <iostream>

TestNTP::TestNTP(int size):GenNS(size)
{
    //ctor
    this -> size = size;
}

void TestNTP::testRandom(){
    NodeSet NS = GenNS.genRandomNodeSet();

    NS.showNodeSet();

    NearestTrioProblem NTP(NS);
    std::pair<float, float> p1, p2, p3;

    double mindistance = NTP.simpleSolution(p1, p2, p3);

    std::cout<<"The minimal distance is: "<<mindistance<<std::endl
            <<"The minimal trio is <"<<p1.first<<", "<<p1.second<<"> "
            <<"<"<<p2.first<<", "<<p2.second<<"> "
            <<"<"<<p3.first<<", "<<p3.second<<">"<<std::endl;

}
