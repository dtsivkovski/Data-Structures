#include "GenStack.h"
#include "LinkedList.h"

GenStack::GenStack(){
    ll = new LinkedList;
}

GenStack::~GenStack() {
    cout << "Stack destroyed" << endl;
    delete ll;
}

void GenStack::push(int data){
    ll->insertBack(data);
}

int GenStack::pop(){
    // TODO: check if empty
    if (ll->isEmpty()) {
        throw runtime_error("Stack is empty, nothing to pop");
    }

    return ll->removeFront();
}


bool GenStack::isEmpty() {
    return (ll->isEmpty());
}

int GenStack::getSize() {
    return ll->getSize();
}

