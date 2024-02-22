#include "Model.h"

Model::Model(){
}

Model::~Model() {
}

string Model::translateSingleConsonant(char consonant) {
    // make an empty string, then append the Rovarsprakt of consonant form
    string result = "";
    result += consonant;
    result += 'o';
    result += tolower(consonant);
    return result;
}

string Model::translateSingleVowel(char vowel) {
    // make the empty string, then append rovarspraket of vowel
    string result = "";
    result += vowel;
    return result;
}   