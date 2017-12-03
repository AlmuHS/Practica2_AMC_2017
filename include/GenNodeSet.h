#ifndef GENNODESET_H
#define GENNODESET_H

#include <random>

#include "NodeSet.h"

class GenNodeSet
{

public:
    GenNodeSet(int size);
    NodeSet genRandomNodeSet();


protected:

private:
    int size;
    NodeSet _NS;
};

#endif // GENNODESET_H
