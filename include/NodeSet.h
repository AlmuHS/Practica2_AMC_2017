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
    NodeSet(const NodeSet& NS);

    void addPair(float x, float y);
    std::pair<float, float> getPair(int position);
    int getSize();
    void swapPair(int i, int j);
    void showNodeSet();
};


#endif // NODESET_H
