#include "World.h"

World::World(unsigned int L, unsigned int N, unsigned int coins, unsigned int nothing, unsigned int goombas, unsigned int koopas, unsigned int mushrooms) {

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

        // create a new char*** to hold L number of char** 
        world = new char**[L]();
        // iterate through number of levels
        for (int i = 0; i < L; i++) {
            
            char** tempLevel = new char*[N]();
            // iterate through each line of the level
            for (int j = 0; j < N; j++) {
                
                char* tempLine = new char[N]();
                // iterate through each char in each line
                for (int k = 0; k < N; k++) {
                    
                    int val = rand() % 100 + 1;

                    if (tempLine[k] == 'w' || tempLine[k] == 'b') {
                        break;
                    }
                    else if (val >= 1 && val < coinsThreshold) {
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

            world[i] = tempLevel;

        }

        // set level counter to 0
        levelcounter = 0;

    }
}