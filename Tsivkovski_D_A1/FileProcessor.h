// FileProcessor header file

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include "Translator.h"

class FileProcessor {

    public:
        FileProcessor();
        ~FileProcessor();

        void processFile(string inputFile, string outputFile);

    private:
        string htmlFormat(string english, string rovarspraket);
        Translator *translator;

};

#endif