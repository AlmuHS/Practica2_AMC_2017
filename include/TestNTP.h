#ifndef TESTNTP_H
#define TESTNTP_H

#include "../include/GenNodeSet.h"
#include "../include/NearestTrioProblem.h"

class TestNTP
{
    public:
        TestNTP(int size);

        void testRandom();

    protected:

    private:

    int size;
    GenNodeSet GenNS;
};

#endif // TESTNTP_H
