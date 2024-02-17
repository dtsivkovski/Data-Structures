#include "GenStack.h"

GenStack::GenStack(){
    mSize = 64; // default stack size
    top = -1;
    myArray = new char[mSize];
}

GenStack::GenStack(int maxSize){
    mSize = maxSize; // custom max stack size
    top = -1;
    myArray = new char[mSize];
}

GenStack::~GenStack() {
    cout << "Stack destroyed" << endl;
    delete[] myArray;
}

void GenStack::push(char data){
    // resize if stack is full
    if (isFull()) {
        cout << "stack resizing" << endl;
        char *temp = new char[2*mSize];
        
        // copy data from old array to new array
        for (int i = 0; i < mSize; ++i) {
            temp[i] = myArray[i]; 
        }

        mSize *= 2; 
        delete[] myArray;
        myArray = temp;
    }

    myArray[++top] = data;
}

char GenStack::pop(){
    // TODO: check if empty
    if (isEmpty()) {
        throw runtime_error("Stack is empty, nothing to pop");
    }

    return myArray[top--];
}

char GenStack::peek(){
    // TODO: check if empty
    if (isEmpty()) {
        throw runtime_error("Stack is empty, nothing to peek");
    }

    return myArray[top];
}

bool GenStack::isFull() {
    return (top == mSize -1);
}

bool GenStack::isEmpty() {
    return (top == -1);
}

int GenStack::getSize() {
    return top + 1;
}

