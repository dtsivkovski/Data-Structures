// Header file for GenQueue

#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>
using namespace std;

class GenQueue {

    public:
        // constructors + destructor
        GenQueue();
        GenQueue(int maxSize);
        ~GenQueue();

        // core functions
        void insert(char data); // enqueue
        char remove(); // dequeue
        void enqueue(char data); // priority queue insert

        // aux functions
        char peek(); // front
        bool isFull();
        bool isEmpty();
        unsigned int getSize();
        void printArray();

    private:
        unsigned int mSize;
        unsigned int front;
        unsigned int rear;
        unsigned int numElements;
        char *myQueue;

};


#endif