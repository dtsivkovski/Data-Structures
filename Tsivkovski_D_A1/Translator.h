// Translator header file

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include<iostream>
#include "Model.h"

using namespace std;

class Translator {

    public:
        Translator();
        ~Translator();

        string translateEnglishWord(string word);
        string translateEnglishSentence(string sentence);

    private:
        Model *model;

};


#endif