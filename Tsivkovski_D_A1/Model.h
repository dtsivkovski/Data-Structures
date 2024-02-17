// Model header

#ifndef MODEL_H
#define MODEL_H

#include<iostream>
using namespace std;

class Model {

    public:
        Model();
        ~Model();

        string translateSingleConsonant(char consonant);
        string translateSingleVowel(char vowel);

    private:
};

#endif