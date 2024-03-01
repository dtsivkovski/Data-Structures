#ifndef MARIO_H
#define MARIO_H

#include <iostream>
using namespace std;

class Mario{

    public:
        Mario(int mLives);
        ~Mario();
        int move();
        void interact();

    private:
        World *world;
        int getLives();
        int getPL();
        void loseLife();
        void addLife();
        void losePL();
        int coins;
        int lives;
        int powerLevel;
        int enemyStreak;
        


};

#endif