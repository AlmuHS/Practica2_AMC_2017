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

    //Generate a new NodeSet with random elements
    NodeSet genRandomNodeSet(int size);

    //Sort the NodeSet using x coordinate, using ShellSort
    NodeSet xSortNodeSet();

    //Generate a new NodeSet from a datafile
    NodeSet genNodeSetFromFile(std::string filename);
};

#endif // GENNODESET_H
