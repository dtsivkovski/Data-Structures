#include "Model.h"

Model::Model(){
    cout << "Model Constructor" << endl;
}

Model::~Model() {
    cout << "Model Destructor" << endl;
}

string Model::translateSingleConsonant(char consonant) {
    // make an empty string, then append the Rovarsprakt of consonant form
    string result = "";
    result += consonant;
    result += 'o';
    result += consonant;
    return result;
}

string Model::translateSingleVowel(char vowel) {
    // make the empty string, then append rovarspraket of vowel
    string result = "";
    result += vowel;
    return result;
}   