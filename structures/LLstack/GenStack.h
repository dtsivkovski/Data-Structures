// header file for GenStack.h

// header guard
#ifndef GENSTACK_H
#define GENSTACK_H
#include "LinkedList.h"

#include<iostream>
#include<exception>
using namespace std;

// define the class
class GenStack{
    public:
        GenStack(); // constructor
        ~GenStack(); // destructor

        // core functions
        void push(int data);
        int pop();
        // char peek(); // aka top

        // aux/helper functions
        bool isEmpty();
        int getSize();

    private:
        LinkedList *ll; 

};

// Rene "slay" counter: 12

#endif