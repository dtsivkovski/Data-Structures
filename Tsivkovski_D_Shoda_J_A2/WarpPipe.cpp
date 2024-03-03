#include "WarpPipe.h"

WarpPipe::WarpPipe(World &worldRef, Mario &marioPlayer){
    world = &worldRef;
    mario = &marioPlayer;
    srand(time(nullptr)); // random seed
}

WarpPipe::~WarpPipe(){};

void WarpPipe::warp() {

    int placementX;
    int placementY;

    int dimensions = world->getDimensions();
    
    do {
        placementX = rand() % dimensions;
        placementY = rand() % dimensions;
    }
    while (world->checkNextLevelPos(placementX,placementY) != 'x');

    world->incrementLevelNum(); // increment level number
    world->updateCharAt(world->getLevelNum(), placementX, placementY, 'H'); // place mario there

    mario->setPosX(placementX);
    mario->setPosY(placementY);

}
