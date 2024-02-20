// header file for GenStack.h

// header guard
#ifndef GENSTACK_H
#define GENSTACK_H

#include<iostream>
#include<exception>
using namespace std;

// define the class
class GenStack{
    public:
        GenStack(); // constructor
        GenStack(int maxSize); // overloaded constructor
        ~GenStack(); // destructor

        // core functions
        void push(char data);
        char pop();
        char peek(); // aka top

        // aux/helper functions
        bool isEmpty();
        bool isFull();
        int getSize();

    private:
        char *myArray; // pointer to the array
        int top; 
        int mSize;

};

// Rene "slay" counter: 12

#endif