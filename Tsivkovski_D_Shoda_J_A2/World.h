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
        char** getLevel();
        char checkNextLevelPos(int xPos, int yPos);
        void printLevel(int levelNumber);
        void printWorld();
        int getLevelNum();
        void incrementLevelNum();
        int getDimensions();
        void updateCharAt(int levelNumber, int xPos, int yPos, char c);
        bool isFinalLevel();

    private:
        int dimensions;
        char*** world;
        int levelcounter;
        int numLevels;
        char** makeLevel();

};

#endif