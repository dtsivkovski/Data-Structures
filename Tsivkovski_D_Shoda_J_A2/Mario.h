#ifndef MARIO_H
#define MARIO_H

#include "World.h"
#include "Enemy.h"
#include "Boss.h"
#include "WarpPipe.h"

#include <iostream>
using namespace std;

class Mario{

    public:
        Mario(int mLives, World &world);
        ~Mario();
        void move(int direction);
        bool hasWon();
        bool hasLost();
        int getPL();
        int getLives();
        int getCoins();
        void loseLife();
        int addPL();
        void addLife();
        void losePL();
        int getPosX();
        int getPosY();
        void setPosX(int positionX);
        void setPosY(int positionY);
        string getLastInteraction();

    private:
        void interact(int posX, int posY);
        string lastInteraction;
        World *world;
        void addCoin();
        int coins;
        int lives;
        int powerLevel;
        int enemyStreak;
        int posX;
        int posY;
        int dimensions;
        bool won;
        bool lost;
        void createMario();
        
};

#endif