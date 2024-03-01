#include "Mario.h"

Mario::Mario(int mLives){
    lives = mLives;
    coins = 0;
    powerLevel = 0;
    enemyStreak = 0;
}

Mario::~Mario(){};



void Mario::interact(){
    
}

int Mario::getLives(){
    return lives;
}

int Mario::getPL(){
    return powerLevel;
}

void Mario::loseLife(){
    lives--;
    }

void Mario::addLife(){
    lives++;
}

void Mario::losePL(){
    powerLevel--;
}
