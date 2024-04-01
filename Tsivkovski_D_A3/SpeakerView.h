#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include "Monostack.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SpeakerView {

    public:
        SpeakerView(string fileName);
        ~SpeakerView();
        void checkVisibility();

    private:
        void getFromLine(string line, int currentRow); // processes the line to the grid data
        void printVisible(int colNumber); // checks for heights that can see the stage, prints them.
        string fileName;
        double **grid;
        Monostack<double> *stack;
};

#endif