#ifndef NODESET_H
#define NODESET_H

#include <vector>
#include <utility>

class NodeSet
{
    std::vector<std::pair<float, float> > node_set;

    public:
        NodeSet(int size);
        NodeSet(const std::vector<std::pair<float, float> > &node_set);

        void gen_random_nodeset();
        void add_pair(float x, float y);
        void get_nodeset(std::vector<std::pair<float, float> >& node_set);

};


#endif // NODESET_H
