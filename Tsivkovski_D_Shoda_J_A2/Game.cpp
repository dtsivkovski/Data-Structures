#include "Game.h"

Game::Game(string inputFile, string outputFile){
    /*
    Line # 1 is the number of levels, L (a positive integer)
    Line # 2 is the dimension of the grid, N (a positive integer)
    Line # 3 is the number of initial lives, V (a positive integer)
    Line # 4 is the approximate percentage of the positions in each level with coins (a positive
    integer)
    Line # 5 is the approximate percentage of the positions in each level with nothing (a positive
    integer)
    Line # 6 is the approximate percentage of the positions in each level with Goombas (a positive
    integer)
    Line # 7 is the approximate percentage of the positions in each level with Koopas (a positive
    integer)
    Line # 8 is the approximate percentage of the positions in each level with mushrooms (a positive
    integer)
    */
    inFile = inputFile;
    outFile = outputFile;
}
Game::~Game(){
    delete mario;
    delete world;
}

void Game::play(){
}
