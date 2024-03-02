#ifndef WORLD_H
#define WORLD_H

#include <iostream>
using namespace std;

class World {

    public:
        World(unsigned int L,
                unsigned int N,
                unsigned int coins,
                unsigned int nothing,
                unsigned int goombas,
                unsigned int koopas,
                unsigned int mushrooms);
        ~World();
        char** getLevel(int levelNumber);
        void printLevel(int levelNumber);
        void printWorld();
        int getLevelNum();
        void incrementLevelNum();

    private:
        int dimensions;
        char*** world;
        int levelcounter;
        int numLevels;
        char** makeLevel();

};

#endif