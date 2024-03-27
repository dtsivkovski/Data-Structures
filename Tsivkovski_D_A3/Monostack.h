// header file for Monostack.h

// header guard
#ifndef MONOSTACK_H
#define MONOSTACK_H

#include<iostream>
#include<exception>
using namespace std;

// define the class
template <typename T>
class Monostack{
    public:
        Monostack(); // constructor
        Monostack(int maxSize, char monotonicDirection); // overloaded constructor
        ~Monostack(); // destructor

        // core functions
        void push(T value);
        T pop();
        T peek(); // aka top

        // aux/helper functions
        bool isEmpty();
        bool isFull();
        int getSize();

    private:
        T *myArray; // pointer to the array
        int top; 
        int mSize;
        char direction;

};

#include "Monostack.cpp"

#endif