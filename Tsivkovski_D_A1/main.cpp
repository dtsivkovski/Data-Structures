#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

int main(int argc, char **argv) {

    // test for arguments
    // second argument is input file, third argument is outputfile
    if (argc < 3) {
        cerr << "Please provide both an input file and output file parameter!" << endl;
        return -1;
    } 

    FileProcessor *f = new FileProcessor; // instantiaton 

    // pass input file (argv[1]) and outputfile (argv[2]) in to process
    f->processFile(argv[1], argv[2]);

    delete f; // garbage collection

    return 0;
}