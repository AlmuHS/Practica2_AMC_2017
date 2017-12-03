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
    NodeSet GenNodeSetFromFile();
};

#endif // GENNODESET_H
