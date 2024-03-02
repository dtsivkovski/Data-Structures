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

    // create ifstream for game parameters, open it
    ifstream *gameInput = new ifstream;
    gameInput->open(inFile);

    if (gameInput->is_open()) {
        
        // create array to hold numerical arguments
        int* args = new int[7];
        string line = "";
        // iterate through lines for arguments
        for (int i = 0; i < 7; ++i) {
            if (getline(*gameInput, line)) {
                args[i] = stoi(line);
            }
        }

        world = new World(args[0], 
                            args[1], 
                            args[2],
                            args[3],
                            args[4],
                            args[5],
                            args[6]);
        world->printWorld();
    }

    delete gameInput;
    
}

