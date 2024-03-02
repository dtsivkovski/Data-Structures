#include "Enemy.h"

Enemy::Enemy(string enemyType) {
    srand(time(nullptr));
    type = enemyType;
    // changes mario win probability based on enemy type
    if (enemyType == "goomba") {
        probability = 80;
    }
    else if (enemyType == "koopa") {
        probability = 65;
    }
    else {
        probability = 0;
    }
}

Enemy::~Enemy() {}

bool Enemy::fight() {
    // generate random value
    int val = rand() % 100 + 1;

    if (val >= 1 && val <= probability) {
        return true; // mario wins
    }
    else {
        return false; // mario loses
    }
}