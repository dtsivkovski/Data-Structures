#include "World.h"
#include "Enemy.h"
#include "Game.h"
#include "Mario.h"

int main(int argc, char** argv) {
    // TO DO: Read the input file, instantiate mario and world 
    // World *world = new World(7,10,10,75,5,5,5); // line for testing world creation
    // world->printWorld();
    // delete world;

    Game *game = new Game("infile.txt", "outfile.txt");
    game->play();
    delete game;

    // Enemy *goomba = new Enemy("goomba");
    // int counter = 0;
    // for (int i = 0; i < 100000; ++i) {
    //     if (goomba->fight()) {
    //         counter++;
    //     }
    // }
    // cout << counter << endl;
    // delete goomba;

    // Enemy *koopa = new Enemy("koopa");
    // counter = 0;
    // for (int i = 0; i < 100000; ++i) {
    //     if (koopa->fight()) {
    //         counter++;
    //     }
    // }
    // cout << counter << endl;
    // delete koopa;

    
}