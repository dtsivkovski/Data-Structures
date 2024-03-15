#include "Boss.h"

Boss::Boss(Mario &marioPlayer){
    mario = &marioPlayer;
}

Boss::~Boss(){}

bool Boss::fight(){

    int val = rand() % 2 + 1; // 50% cance of winning

    if (val == 1) {
        return true; // mario wins
    }
    else if (mario->getPL() <= 1) {
        mario->loseLife();
        return false; // mario loses the fight
    }
    else {
        // mario loses power level but has the chance to fight agian
        mario->losePL();
        mario->losePL();
        return fight(); // recursive call to fight again
    }

}