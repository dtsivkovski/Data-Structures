#include "World.h"

World::World(unsigned int L, unsigned int N, unsigned int coins, unsigned int nothing, unsigned int goombas, unsigned int koopas, unsigned int mushrooms) {

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

                if ()

            }

            
        }

    }
}