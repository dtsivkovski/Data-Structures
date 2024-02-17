#include "FileProcessor.h"

FileProcessor::FileProcessor() {
    cout << "File Processor Constructed" << endl;
    translator = new Translator();
}

FileProcessor::~FileProcessor() {
    cout << "File Processor Destructed" << endl;
    delete translator;
}

void FileProcessor::processFile(string inputFile, string outputFile) {

    // create input file stream and open it
    ifstream inFile;
    inFile.open(inputFile);
    // only execute first if input file open
    if (inFile.is_open()) {
        
        // sentence string for the translation
        string englishSentence = "";

        // reads from input file to append everything to a sentence
        string line;
        while (getline(inFile, line)) {
            englishSentence += line;
        }

        // close input file
        inFile.close();

        // once done, translate it, then format to html
        string rovarspraket = translator->translateEnglishSentence(englishSentence);
        string formattedOutput = htmlFormat(englishSentence, rovarspraket);

        // create output file stream and open it
        ofstream outFile;
        outFile.open(outputFile);
        if (outFile.is_open()) {
            // write formatted output to it
            outFile << formattedOutput;
            outFile.close();
        }
        else {
            // error message for output file open
            cerr << "Could not open the output file successfully, please try agian!" << endl;
        }
        
    }
    else {
        // error message for file open
        cerr << "Could not open the input file successfully, try again!" << endl;
    }

    return;
}

string FileProcessor::htmlFormat(string english, string rovarspraket) {
    string result = "";
    /*
        HTML FORMATING
        - the brs are breaks that add an empty line gap in between
    */
    result += "<!DOCTYPE html><html><body><b>" + english + "</b><br/><br/>";
    result += "<i>" + rovarspraket + "</i></body></html>"; // closing tags
    return result;
}