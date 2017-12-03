#ifndef TESTNTP_H
#define TESTNTP_H

#include "../include/GenNodeSet.h"
#include "../include/NearestTrioProblem.h"

#include <string>

class TestNTP
{
private:

    GenNodeSet GenNS;

public:
    TestNTP();

    void testRandom(int size);
    void testFromFile(std::string filename);
};

#endif // TESTNTP_H
