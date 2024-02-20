// header file for TextAnalyzer

// header guard - only include it once 
#ifndef TEXTANALYZER_H // if not defined
#define TEXTANALYZER_H // then define it 

#include<iostream> // pre-processor directive
using namespace std; // namespace definition

// define the class
class TextAnalyzer{

    // access modifiers written like this
    public: 
        TextAnalyzer(); // constructor
        ~TextAnalyzer(); // destructor (~)
    
        int countVowels(string userInput); // countVowels defined here

    private:
}; 

#endif 

