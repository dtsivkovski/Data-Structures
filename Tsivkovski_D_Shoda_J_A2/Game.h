#ifndef GAME_H
#define GAME_H

#include "Mario.h"
#include "World.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Game {

    public:
        Game(string inputFile, string outputFile);
        ~Game();
        void play();

    private:
        World *world;
        Mario *mario;
        string inFile;
        string outFile;
        string createLineOutput();
        int powerLevel;
        int nextDirection;

};

#endif