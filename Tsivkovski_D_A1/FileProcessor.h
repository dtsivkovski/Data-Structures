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
        string htmlEnglishFormat(string english);
        string htmlRovarspraketFormat(string rovarspraket);
        string createHTMLHead();
        string createHTMLEnding();
        Translator *translator;

};

#endif