#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;

class Enemy{

    public:

        Enemy(string enemyType);
        ~Enemy();
        
        bool fight();

    private:
        string type;
        int probability;
        
};

#endif