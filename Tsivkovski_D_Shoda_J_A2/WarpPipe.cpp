#include "WarpPipe.h"

WarpPipe::WarpPipe(World &worldRef, Mario &marioPlayer){
    world = &worldRef;
    mario = &marioPlayer;
    srand(time(nullptr)); // random seed
}

WarpPipe::~WarpPipe(){};

void WarpPipe::warp() {

    // placement of warp pipe
    int placementX;
    int placementY;

    int dimensions = world->getDimensions();
    
    do {
        // attempts to get random position for the warp pipe to place mario at
        placementX = rand() % dimensions;
        placementY = rand() % dimensions;
    }
    while (world->checkNextLevelPos(placementX,placementY) != 'x'); // won't place mario at a non-empty spot

    world->incrementLevelNum(); // increment level number
    world->updateCharAt(world->getLevelNum(), placementX, placementY, 'H'); // place mario there

    // set mario's position
    mario->setPosX(placementX);
    mario->setPosY(placementY);

}
