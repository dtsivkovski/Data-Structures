#include "World.h"
#include "Enemy.h"
#include "Game.h"
#include "Mario.h"

int main(int argc, char** argv) {

    // gets the two files from the command line
    if (argc < 3) {
        return -1;
    }

    // reads in the two files
    Game *game = new Game(argv[1], argv[2]);
    game->play();
    delete game;
    
}