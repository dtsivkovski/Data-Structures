#include "FileProcessor.h"

FileProcessor::FileProcessor() {
    translator = new Translator();
}

FileProcessor::~FileProcessor() {
    delete translator;
}

void FileProcessor::processFile(string inputFile, string outputFile) {

    // create input file stream and open it
    ifstream inFile;
    inFile.open(inputFile);
    // only execute first if input file open
    if (inFile.is_open()) {
        
        // sentence string for the translation
        string englishSentences = "";
        string rovarspraket = "";

        // reads from input file to append everything to a sentence
        string line;
        while (getline(inFile, line)) {
            // format the english sentence
            englishSentences += htmlEnglishFormat(line); 
            // format and append after being translated to rovarspraket
            rovarspraket += htmlRovarspraketFormat(translator->translateEnglishSentence(line));
        }

        // close input file
        inFile.close();

        // create the HTML file string
        string formattedOutput = createHTMLHead();
        formattedOutput += englishSentences;
        formattedOutput += "<br/><br/>"; // br is to create the gap in between the two
        formattedOutput += rovarspraket;
        formattedOutput += createHTMLEnding();


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

string FileProcessor::createHTMLHead() {
    // creates the header tags and opens container for body
    string result = "";
    result += "<!DOCTYPE html>\n<html>\n<head>\n<title>English to Robber Translation</title>\n</head>\n<body>\n";
    return result;
}

string FileProcessor::htmlEnglishFormat(string english) {
    // creates a bolded div for the english words
    string result = "<p><b>" + english + "</b><br></p>\n";
    return result;
}

string FileProcessor::htmlRovarspraketFormat(string rovarspraket) {
    // creates an italicizes div for the rovarspraket translation
    string result = "<p><i>" + rovarspraket + "</i><br></p>";
    return result;
}

string FileProcessor::createHTMLEnding() {
    // closes the remaining HTML elements
    string result = "";
    result += "</body>\n</html>";
    return result;
}