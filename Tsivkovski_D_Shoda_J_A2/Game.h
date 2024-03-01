#ifndef GAME_H
#define GAME_H

#include "Mario.h"
#include "World.h"

#include <iostream>
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


};

#endif