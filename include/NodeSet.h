#ifndef NODESET_H
#define NODESET_H

#include <vector>
#include <utility>

class NodeSet
{
    std::vector<std::pair<float, float> > node_set;

    public:
        NodeSet(int size);
        NodeSet(const NodeSet& NS);

        void gen_random_nodeset();
        void add_pair(float x, float y);
        std::pair<float, float> get_pair(int position);
        int get_size();
};


#endif // NODESET_H
