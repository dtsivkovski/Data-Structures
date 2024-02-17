#include "Translator.h"

Translator::Translator(){
    cout << "Translator Constructor" << endl;
    model = new Model();
}

Translator::~Translator(){
    cout << "Translator Destructor" << endl;
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
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                /* BEGIN CODE BEING REFERENCED:
                    https://www.geeksforgeeks.org/stdstringappend-in-c/
                */
                result.append(model->translateSingleVowel(word[i]));
                break;
            // assume that anything not a vowel is a consonant for a regular english word
            default:
                result.append(model->translateSingleConsonant(word[i]));
                /* END CODE BEING REFERENCED:
                    https://www.geeksforgeeks.org/stdstringappend-in-c/
                */
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
            result.append(translateEnglishWord(word)).append(" "); // translate it and append a space
            wordStartPos = i + 1; // reset position to the one after the space char
        }
         /* make sure to translate the last word if there are any characters left after a space
            the else if (as opposed to if) prevents an error when a space is the last char in a sentence
         */
        else if (i == sentence.size() - 1) {
            string word = sentence.substr(wordStartPos, i);
            result.append(translateEnglishWord(word));
        }

    }

    return result;
}