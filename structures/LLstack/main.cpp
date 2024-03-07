#include "GenStack.h"

int main(int argc, char **argv) {

    GenStack *myStack = new GenStack();

    try {
        myStack->push(5);
        myStack->push(10);
        myStack->push(15);
        myStack->push(20);
        myStack->push(25);
        myStack->push(30);

        cout << "SIZE: " << myStack->getSize() << endl;
        cout << "POP: " << myStack->pop() << endl;
        cout << "SIZE: " << myStack->getSize() << endl;

        while (!myStack->isEmpty()) {
            cout << "POP: " << myStack->pop() << endl;
        }
        cout << "SIZE: " << myStack->getSize() << endl;
        cout << "POP: " << myStack->pop() << endl;
    }
    catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
    }

    delete myStack;
    return 0;
}