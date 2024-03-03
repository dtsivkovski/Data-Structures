#include "Mario.h"
#include "WarpPipe.h"

Mario::Mario(int mLives, World &worldLevel){
    lives = mLives;
    coins = 0;
    powerLevel = 0;
    enemyStreak = 0;
    srand(time(nullptr)); // random seed
    world = &worldLevel;
    dimensions = world->getDimensions();
    lost = false;
    won = false;
    totalMoves = 0;

    createMario();

}

Mario::~Mario(){};

void Mario::createMario() {
    char** level0 = world->getLevel(); // gets first level 

    // generate random x and y position
    int placementX;
    int placementY; 
    do {
        placementX = rand() % dimensions;
        placementY = rand() % dimensions;
    }
    while (level0[placementX][placementY] != 'x');

    // change mario in world and update his coordinates
    world->updateCharAt(0, placementX, placementY, 'H');
    posX = placementX;
    posY = placementY;
}

void Mario::move(int direction) {
    totalMoves++; // increment move counter for final total

    if(direction == 1){ // up
        if(posY + 1 >= dimensions){ // if higher than boundary
            interact(posX, 0);
        }
        else {
            interact(posX, posY + 1);
        }
    }
    else if(direction == 2){ // down
        
        if(posY - 1 < 0){ // if less than edge of Y coordinate
            interact(posX, dimensions - 1);
        }
        else {
            interact(posX, posY - 1);
        }
    }
    else if(direction == 3){ // left

        if(posX - 1 < 0){ // if less than edge of X coordinate
            interact(dimensions - 1, posY);
        }
        else {
            interact(posX - 1, posY);
        }
    }
    else { // right
        
        if(posX + 1 >= dimensions){ // if greater than upper edge of x coordinates
            interact(0, posY);
        }
        else{
            interact(posX + 1, posY);
        }
    }
}

void Mario::interact(int nextPosX, int nextPosY) {
    char posChar = world->getLevel()[nextPosX][nextPosY]; // gets char of the next position
    int levelNumber = world->getLevelNum();
    WarpPipe *wp = nullptr;
    Enemy *koopa = nullptr;
    Enemy *goomba = nullptr;
    Boss *boss = nullptr;

    switch(posChar) {
        case 'c':
            addCoin();
            world->updateCharAt(levelNumber, posX, posY, 'x'); // reset old space to nothing
            world->updateCharAt(levelNumber, nextPosX, nextPosY, 'H'); // reset new space to hero
            posX = nextPosX;
            posY = nextPosY;
            lastInteraction = "Mario collected a coin";
            break;
        case 'm':
            addPL();
            world->updateCharAt(levelNumber, posX, posY, 'x'); // reset old space to nothing
            world->updateCharAt(levelNumber, nextPosX, nextPosY, 'H'); // reset new space to hero
            posX = nextPosX;
            posY = nextPosY;
            lastInteraction = "Mario ate a mushroom";
            break;
        case 'x':
            world->updateCharAt(levelNumber, posX, posY, 'x'); // reset old space to nothing
            world->updateCharAt(levelNumber, nextPosX, nextPosY, 'H'); // reset new space to hero
            posX = nextPosX;
            posY = nextPosY;
            lastInteraction = "The position is empty";
            break;
        case 'g':
            goomba = new Enemy("goomba");
            if (goomba->fight()) {
                world->updateCharAt(levelNumber, posX, posY, 'x'); // reset old space to nothing
                world->updateCharAt(levelNumber, nextPosX, nextPosY, 'H'); // reset new space to hero
                posX = nextPosX;
                posY = nextPosY;
                enemyStreak++;
                lastInteraction = "Mario fought a goomba and won";
            }
            else {
                losePL(); // if mario loses, nothing changes but he loses powerlevel
                enemyStreak = 0;
                lastInteraction = "Mario fought a goomba and lost";
            }
            delete goomba;
            goomba = nullptr;
            break;
        case 'k':
            koopa = new Enemy("koopa");
            if (koopa->fight()) {
                world->updateCharAt(levelNumber, posX, posY, 'x'); // reset old space to nothing
                world->updateCharAt(levelNumber, nextPosX, nextPosY, 'H'); // reset new space to hero
                posX = nextPosX;
                posY = nextPosY;
                enemyStreak++;
                lastInteraction = "Mario fought a koopa and won";
            }
            else {
                losePL(); // if mario loses, nothing changes but he loses powerlevel
                enemyStreak = 0;
                lastInteraction = "Mario fought a koopa and lost";
            }
            delete koopa;
            koopa = nullptr;
            break;
        case 'b':
            boss = new Boss(*this);
            if (boss->fight()) {
                world->updateCharAt(levelNumber, posX, posY, 'x'); // reset old space to nothing
                world->updateCharAt(levelNumber, nextPosX, nextPosY, 'x'); // reset new space to nothing
                posX = nextPosX;
                posY = nextPosY;
                enemyStreak++;
                lastInteraction = "Mario fought the level boss and won";
                // win condition if mario beats boss at the last level
                if (world->isFinalLevel()) {
                    won = true;
                }
                else { // move mario to next level (use warppipe method) if not the last level
                    wp = new WarpPipe(*world, *this);
                    wp->warp();
                    delete wp;
                    wp = nullptr;
                }
            }
            else {
                lastInteraction = "Mario fought the level boss and lost";
                enemyStreak = 0;
            }
            delete boss;
            boss = nullptr;
            break;
        case 'w':
            wp = new WarpPipe(*world, *this);
            world->updateCharAt(levelNumber, posX, posY, 'x'); // reset old space to nothing
            wp->warp(); // warp mario to next level
            lastInteraction = "Mario warped";
            delete wp;
            wp = nullptr;
            break;
        default:
            return;
    }
}

int Mario::getLives(){
    return lives;
}

int Mario::addPL(){
    if(powerLevel < 2){
        powerLevel++;
    }
    return powerLevel;
}

void Mario::loseLife(){
    if(lives == 0){
        lost = true;
    }
    else{
        lives--;
        powerLevel = 0;
    }
}

void Mario::addLife(){
    lives++;
}

void Mario::losePL(){
    if(powerLevel > 0){
        powerLevel--;
    }
    else{
        loseLife();
    }
}

int Mario::getPL() {
    return powerLevel;
}

void Mario::addCoin(){
    if(coins == 20){
        addLife();
        coins = 0;
    }
    else{
        coins++;
    }
}

bool Mario::hasWon() {
    return won;
}

bool Mario::hasLost() {
    return lost;
}

int Mario::getPosX() {
    return posX;
}

int Mario::getPosY() {
    return posY;
}

void Mario::setPosX(int positionX) {
    posX = positionX;
}

void Mario::setPosY(int positionY) {
    posY = positionY;
}

string Mario::getLastInteraction() {
    return lastInteraction;
}

int Mario::getCoins(){
    return coins;
}

int Mario::getTotalMoves() {
    return totalMoves;
}