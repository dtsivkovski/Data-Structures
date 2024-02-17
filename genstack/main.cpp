#include "GenStack.h"

int main(int argc, char **argv) {

    GenStack *myStack = new GenStack(5);

    try {
        myStack->push('f');
        myStack->push('o');
        myStack->push('o');
        myStack->push('b');
        myStack->push('a');
        myStack->push('r');

        cout << "SIZE: " << myStack->getSize() << endl;
        cout << "PEEK: " << myStack->peek() << endl;
        cout << "POP: " << myStack->pop() << endl;
        cout << "SIZE: " << myStack->getSize() << endl;
        cout << "PEEK: " << myStack->peek() << endl;

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