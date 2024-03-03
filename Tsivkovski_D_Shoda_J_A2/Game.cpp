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
        int* args = new int[8];
        string line = "";
        // iterate through lines for arguments
        for (int i = 0; i < 8; ++i) {
            if (getline(*gameInput, line)) {
                args[i] = stoi(line);
            }
        }


        world = new World(args[0], 
                            args[1], 
                            args[3],
                            args[4],
                            args[5],
                            args[6],
                            args[7]);
        world->printWorld();

        // TO DO: Initialize Mario with lives (V) of args[2]
        mario = new Mario(args[2], *world);
    }

    delete gameInput;

    ofstream *gameOutput = new ofstream;
    gameOutput->open(outFile);

    if (gameOutput->is_open()) {

        
        while (!(mario->hasLost() + mario->hasWon())) {
            nextDirection = rand() % 5 + 1; // get next direction of movement
            powerLevel = mario->getPL();
            mario->move(nextDirection);
            *gameOutput << createLineOutput();
        }
        
    }

    delete gameOutput;
    
}

string Game::createLineOutput() {
    string result = "LVL: ";
    result += to_string(world->getLevelNum()) + " | "; // appends level num
    result += "(" + to_string(mario->getPosX()) + "," + to_string(mario->getPosY()) + ") | ";
    result += "PL: " + to_string(powerLevel) + " | ";
    result += mario->getLastInteraction() + " | ";
    result += "Lives: " + to_string(mario->getLives()) + " | ";
    result += "Coins: " + to_string(mario->getCoins()) + " | ";

    // append next direction
    string directionWord = "";
    switch(nextDirection) {
        case '1':
            "UP";
            break;
        case '2':
            "DOWN";
            break;
        case '3':
            "LEFT";
            break;
        case '4':
            "RIGHT";
            break;
        default:
            "STAY PUT";
            break;
    }
    result += "Direction: " + directionWord;
    
    return result;
    


}
