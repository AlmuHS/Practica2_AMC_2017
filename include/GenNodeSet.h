#ifndef GENNODESET_H
#define GENNODESET_H

#include <random>

#include "NodeSet.h"

class GenNodeSet
{
    NodeSet _NS;

    public:
        GenNodeSet(int size);
        void genRandomNodeSet();

    protected:

    private:
};

#endif // GENNODESET_H
