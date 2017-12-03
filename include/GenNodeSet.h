#ifndef GENNODESET_H
#define GENNODESET_H

#include <random>
#include <string>

#include "NodeSet.h"

class GenNodeSet
{

private:
    NodeSet _NS;

public:
    GenNodeSet();
    NodeSet genRandomNodeSet(int size);
    NodeSet xSortNodeSet();
    NodeSet genNodeSetFromFile(std::string filename);
};

#endif // GENNODESET_H
