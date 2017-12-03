#ifndef GENNODESET_H
#define GENNODESET_H

#include <random>

#include "NodeSet.h"

class GenNodeSet
{

private:
    NodeSet _NS;

public:
    GenNodeSet();
    NodeSet genRandomNodeSet(int size);
    NodeSet genXSortedNodeSet(int size);
};

#endif // GENNODESET_H
