#include "World.h"

int main(int argc, char** argv) {
    // TO DO: Read the input file, instantiate mario and world 
    World *world = new World(7,10,10,75,5,5,5); // line for testing world creation
    for (int i = 0; i < 7; ++i) {
        world->printLevel(i);
    }
}