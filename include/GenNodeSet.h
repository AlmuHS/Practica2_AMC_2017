#ifndef GENNODESET_H
#define GENNODESET_H

#include <random>
#include <string>

using NodeSet = std::vector<std::pair<float, float> >;

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

    //Shows the contents of NodeSet by screen
    void showNodeSet();
};

#endif // GENNODESET_H
