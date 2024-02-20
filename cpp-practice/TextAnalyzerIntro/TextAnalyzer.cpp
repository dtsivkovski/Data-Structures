// implementation file for textanalyzer

#include "TextAnalyzer.h" // include header file
// ifndef in TextAnalyzer.h prevents it from being included more than once
//
// DEFINITIONS: 
// <> for system-defined
// "" for user-defined

// IMPLEMENTATION
// prefix name of method with the name of the class
TextAnalyzer::TextAnalyzer(){
    cout << "constructor" << endl;
}

TextAnalyzer::~TextAnalyzer(){
    cout << "destructor" << endl;
}

int TextAnalyzer::countVowels(string userInput){

    int count = 0;

    for (int i = 0; i < userInput.size(); ++i) { // ++i is always more efficient in a for loop
        if(tolower(userInput[i]) == 'a')
            count++;
        else if(tolower(userInput[i]) == 'e')
            count++;
        else if(tolower(userInput[i]) == 'i')
            count++;
        else if(tolower(userInput[i]) == 'o')
            count++;
        else if(tolower(userInput[i]) == 'u') 
            count++;
    }

    return count;
}