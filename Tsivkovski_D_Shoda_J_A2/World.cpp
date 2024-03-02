#include "World.h"

World::World(unsigned int L, unsigned int N, unsigned int coins, unsigned int nothing, unsigned int goombas, unsigned int koopas, unsigned int mushrooms) {
    
    srand(time(nullptr));

    if ((coins + nothing + goombas + koopas + mushrooms) != 100) {
        cerr << "Percentages do not add up to 100" << endl;
    }
    else {
    
        // instantiate thresholds for random number generation
        int coinsThreshold = coins + 1;
        int nothingThreshold = coinsThreshold + nothing;
        int goombaThreshold = nothingThreshold + goombas;
        int koopaThreshold = goombaThreshold + koopas;
        int mushroomThreshold = koopaThreshold + mushrooms;

        dimensions = N;


        // create a new char*** to hold L number of char** 
        world = new char**[L]();
        // iterate through number of levels
        for (int i = 0; i < L; ++i) {
            
            char** tempLevel = new char*[N]();
            // iterate through each line of the level
            for (int j = 0; j < N; ++j) {
                
                char* tempLine = new char[N]();
                // iterate through each char in each line
                for (int k = 0; k < N; ++k) {
                    
                    // generate a random number from 1 - 100
                    int val = rand() % 100 + 1;
                    
                    /*
                        Ex: 
                        - a number from 1 to coinsThreshold will be a 'c'
                        - then, a number from coinsThreshold to nothingThreshold will be an 'x'
                        - etc.
                    */
                    if (val >= 1 && val < coinsThreshold) {
                        tempLine[k] = 'c';
                    }
                    else if (val >= coinsThreshold && val < nothingThreshold) {
                        tempLine[k] = 'x';
                    }
                    else if (val >= nothingThreshold && val < goombaThreshold) {
                        tempLine[k] = 'g';
                    }
                    else if (val >= goombaThreshold && val < koopaThreshold) {
                        tempLine[k] = 'k';
                    }
                    else {
                        tempLine[k] = 'm';
                    }

                }
                tempLevel[j] = tempLine;

                
            }

            // every level (except the last) should have a warp pipe
            if (!(i == (L - 1))) {
                // generate coordinates for warp pipe
                int xrand = rand() % N;
                int yrand = rand() % N;
                
                if (!(nothing == 0)) { // prevents infinite loop when no empty spaces
                    while (tempLevel[xrand][yrand] != 'x') {
                        // continue redoing until locating an empty space to put the warp pipe
                        xrand = rand() % N;
                        yrand = rand() % N;
                    }
                }
                // set random location to warp pipe

                tempLevel[xrand][yrand] = 'w';

            }

            // now generate a boss location for each level
            int b_xrand = rand() % N;
            int b_yrand = rand() % N;

            if (!(nothing == 0)) { // prevents infinite loop when no empty spaces
                while (tempLevel[b_xrand][b_yrand] != 'x') {
                    // continue redoing until locating an empty space to put the boss
                    b_xrand = rand() % N;
                    b_yrand = rand() % N;
                }
            }
            // place boss char
            tempLevel[b_xrand][b_yrand] = 'b';

            world[i] = tempLevel; // set 2d array to the level

        }

        // set level counter to 0
        levelcounter = 0;

    }
}

World::~World() {
    delete world;
}

void World::printLevel(int levelNumber) {
    cout << "Level " << levelNumber  << endl;
    for (int i = 0; i < dimensions; ++i) {

        for (int j = 0; j < dimensions; ++j) {
            cout << world[levelNumber][i][j] << ' ';
        }
        cout << endl;

    }
    cout << endl;
}

char** World::getLevel(int levelNumber) {
    return world[levelNumber];
}

int World::getLevelNum() {
    return levelcounter;
}

void World::incrementLevelNum() {
    levelcounter++;
}
