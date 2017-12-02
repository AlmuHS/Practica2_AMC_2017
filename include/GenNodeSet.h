#ifndef GENNODESET_H
#define GENNODESET_H

#include <random>

#include "NodeSet.h"

class GenNodeSet
{
    NodeSet NS;

    public:
        GenNodeSet(int size);
        void gen_random_nodeset();

    protected:

    private:
};

#endif // GENNODESET_H
