#ifndef WARPPIPE_H
#define WARPPIPE_H

#include "World.h"
#include "Mario.h"
#include <iostream>
using namespace std;

class Mario;

class WarpPipe{
    
    public:
        WarpPipe(World &worldRef, Mario &marioPlayer);
        ~WarpPipe();
        void warp();

    private:
        World *world;
        Mario *mario;
};

#endif