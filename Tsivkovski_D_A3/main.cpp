#include "Monostack.h"

int main(int argc, char **argv) {

    Monostack<double> *myStack = new Monostack<double>(6, 'i');
    Monostack<double> *mySecondStack = new Monostack<double>(6, 'd');

    try {
        myStack->push(1.0);
        cout << "PEEK: " << myStack->peek() << endl;
        myStack->push(3.0);
        cout << "PEEK: " << myStack->peek() << endl;
        myStack->push(5.5);
        cout << "PEEK: " << myStack->peek() << endl;
        myStack->push(2.0);
        cout << "PEEK: " << myStack->peek() << endl;
        myStack->push(4.0);
        cout << "PEEK: " << myStack->peek() << endl;
        myStack->push(6.0);
        cout << "PEEK: " << myStack->peek() << endl;
        cout << "POP: " << myStack->pop() << endl;
        cout << "POP: " << myStack->pop() << endl;
        cout << "POP: " << myStack->pop() << endl;
        cout << "POP: " << myStack->pop() << endl;

        mySecondStack->push(1.0);
        cout << "PEEK: " << mySecondStack->peek() << endl;
        mySecondStack->push(3.0);
        cout << "PEEK: " << mySecondStack->peek() << endl;
        mySecondStack->push(2.0);
        cout << "PEEK: " << mySecondStack->peek() << endl;
        mySecondStack->push(4.0);
        cout << "PEEK: " << mySecondStack->peek() << endl;
        mySecondStack->push(3.5);
        cout << "PEEK: " << mySecondStack->peek() << endl;
        mySecondStack->push(0.5);
        cout << "PEEK: " << mySecondStack->peek() << endl;
        cout << "POP: " << mySecondStack->pop() << endl;
        cout << "POP: " << mySecondStack->pop() << endl;
        cout << "POP: " << mySecondStack->pop() << endl;
        cout << "POP: " << mySecondStack->pop() << endl;

    }
    catch (runtime_error &excpt) {
        cout << excpt.what() << endl;
    }

    delete myStack;
    delete mySecondStack;
    return 0;
}