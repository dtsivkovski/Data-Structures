#ifndef WARPPIPE_H
#define WARPPIPE_H

#include "World.h"
#include <iostream>
using namespace std;

class WarpPipe{
    
    public:
        WarpPipe(World &worldRef);
        ~WarpPipe();
        void warp();

    private:
        World *world;
};

#endif