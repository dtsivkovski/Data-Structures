#include "TextAnalyzer.h"
// don't include cpp

int main(int argc, char **argv) {
    // argc = number of arguments (includes name of program)
    // argv = pointer to an array of strings on the command line
    // cout << "ARGC: " << argc << endl;
    // cout << "ARGV: " << argv[0] << endl;

    if (argc < 2) {
        cerr << "Invalid parameter count!" << endl;
        return -1;
    }

    TextAnalyzer ta; // the object is on the STACK -> automatically destructed before return 0
    TextAnalyzer *ta2 = new TextAnalyzer; // this object is on the HEAP -> used keyword new

    cout << "VOWEL COUNT: " << ta.countVowels(argv[1]) << endl; // method on a STACK
    cout << "VOWEL COUNT: " << ta2->countVowels(argv[1]) << endl; // method on a HEAP

    // *ta2 is NOT destructed before return
    // new = REMEMBER TO GARBAGE COLLECT USING "delete"
    delete ta2;

    // ta is automatically destructed
    return 0;
}

// g++ *.cpp -o ta.out 
// compiles all cpp files, -o argument specifies to ta.out

// STACK is SHORT TERM STORAGE but automatically destruct
// HEAP is LONG TERM STORAGE but manually destruct