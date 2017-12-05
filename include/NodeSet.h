#ifndef NODESET_H
#define NODESET_H

#include <vector>
#include <utility>

class NodeSet
{
private:
    std::vector<std::pair<float, float> > node_set;

public:
    NodeSet();

    //Copy constructor
    NodeSet(const NodeSet& NS);

    //Add a new pair to nodeset
    void addPair(float x, float y);

    //Returns the pair of this position
    std::pair<float, float> getPair(int position);

    //Returns the nodeset size
    int getSize();

    //swap two positions in nodeset
    void swapPair(int i, int j);

    //Shows the contents of nodeset by screen
    void showNodeSet();
};


#endif // NODESET_H
