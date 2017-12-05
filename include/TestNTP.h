#ifndef TESTNTP_H
#define TESTNTP_H

#include "../include/GenNodeSet.h"
#include "../include/NearestTrioProblem.h"



class TestNTP
{
private:
    GenNodeSet GenNS;

public:
    TestNTP();

    void testRandom();
    void testFromFile(int algorithm);
};

#endif // TESTNTP_H
