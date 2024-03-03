#ifndef BOSS_H
#define BOSS_H

#include <iostream>
#include "Mario.h"

using namespace std;

class Mario;

class Boss{

    public:

        Boss(Mario &marioPlayer);
        ~Boss();

        bool fight();
    
    private:
        Mario *mario;
        
};

#endif