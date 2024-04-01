#include "SpeakerView.h"

int main(int argc, char **argv) {

    if (argc < 2) {
        return -1;
    }

    SpeakerView *sv = new SpeakerView(argv[1]);
    sv->checkVisibility();
    delete sv;

    // Monostack<double> *myStack = new Monostack<double>(8, 'd');
    // myStack->push(121.4);
    // cout << "PEEK: " << myStack->peek() << endl;
    // myStack->push(50.2);
    // cout << "PEEK: " << myStack->peek() << endl;
    // myStack->push(75.3);
    // cout << "PEEK: " << myStack->peek() << endl;
    // cout << "POP: " << myStack->pop() << endl;
    // delete myStack;

    return 0;

}