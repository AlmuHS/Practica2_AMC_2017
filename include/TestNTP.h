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
    void testFromFile();
};

#endif // TESTNTP_H
