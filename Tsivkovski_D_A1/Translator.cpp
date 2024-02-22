#include "Translator.h"

Translator::Translator(){
    model = new Model();
}

Translator::~Translator(){
    delete model;
}

string Translator::translateEnglishWord(string word) {
    // create empty string
    string result = "";

    // iterate through each character in the word
    for (int i = 0; i < word.size(); ++i) {
        /* switch based on lowercase version of character
         determines whether it is a vowel or consonant*/
        switch(tolower(word[i])) {
            // all consonants
            case 'b':
            case 'c':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                // append the consonant translation
                result += model->translateSingleConsonant(word[i]);
                break;
            // assume that anything not a consonant is a vowel for a regular english word
            // also helps with punctuation not accidentally duplicating
            default:
                result += model->translateSingleVowel(word[i]);
                // append the vowel translation
                break;
        }
    }

    return result;
}

string Translator::translateEnglishSentence(string sentence) {
    
    // empty result string to append to
    string result = "";
    // index tracker for where the start of each word is
    int wordStartPos = 0;


    for(int i = 0; i < sentence.size(); ++i) {

        // find where each word ends by finding a space character
        if (sentence[i] == ' ') {
            // get word by getting word start position up to this point
            string word = sentence.substr(wordStartPos, i - wordStartPos);
            result += translateEnglishWord(word) + " "; // translate and append a space
            wordStartPos = i + 1; // reset position to the one after the space char
        }
         /* make sure to translate the last word if there are any characters left after a space
            the else if (as opposed to if) prevents an error when a space is the last char in a sentence
         */
        else if (i == sentence.size() - 1) {
            string word = sentence.substr(wordStartPos, i);
            result += translateEnglishWord(word);
        }

    }

    return result;
}