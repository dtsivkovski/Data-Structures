#include "SpeakerView.h"

SpeakerView::SpeakerView(string fileName) {
    stack = new Monostack<double>(6, 'd');
    this->fileName = fileName;
}

SpeakerView::~SpeakerView() {
    delete stack;
}

void SpeakerView::checkVisibility() {
    // create new file stream to get input file
    ifstream *inFile = new ifstream();
    inFile->open(fileName);

    // check if file is open, then perform operations
    if (inFile->is_open()) {

        // get each line of the file
        string line;
        int rows = 0;
        int cols = 0;

        // first count the number of columns and rows
        while (getline(*inFile, line)) {

            int currentCols = 0;
            int numStartPos = 0; // position where the current number starts

            // iterate through the entire line
            for (int i = 0; i < line.size(); ++i) {
                if (line[i] == ' ' || line[i] == '\n') { // whitespace detection
                    // get number by getting numStartPos up to this point
                    string temp = line.substr(numStartPos, i - numStartPos);
                    ++currentCols;
                    numStartPos = i + 1; // reset position to the one after the space char
                }
                // make sure to count the last number if there are any characters left after a space
                else if (i == line.size() - 1) {
                    ++currentCols;
                }
            }
            cols = max(cols, currentCols); // in case columns are entered unevenly
            ++rows;

        }
        cout << cols << endl;

        // allocate 2d array based on num of cols adn rows
        grid = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            grid[i] = new double[cols];
        }

        // reset the file stream to beginning
        inFile->clear();
        inFile->seekg(0, ios::beg);

        // read the data per row
        int currentRow = 0;
        while (getline(*inFile, line)) {
            getFromLine(line, currentRow++); // uses method to read line's data
        }

        // push each value into stack by columms
        for (int col = 0; col < cols; ++col) {
            for (int row = rows - 1; row >= 0; --row) {
                stack->push(grid[row][col]); // push everything in column
            }
            printVisible(col); // print col visibility
        }

        // delete data array
        for (int i = 0; i < rows; ++i) {
            delete[] grid[i];
        }
        delete[] grid;

        // close input file
        inFile->close();

    }

    delete inFile;
    return;
}

void SpeakerView::printVisible(int colNumber) {
    string str = "Column " + to_string(colNumber) + " | " + to_string(stack->getSize()) + " people can see the speaker. | Heights: ";

    while (!stack->isEmpty()) {
        str += to_string(stack->pop()) + ", ";
    }

    cout << str << endl;

}

void SpeakerView::getFromLine(string line, int currentRow) {
    
    double num;
    int currentCol = 0;
    int numStartPos = 0; // position where the current number starts

    // iterate through the entire line
    for (int i = 0; i < line.size(); ++i) {

        if (line[i] == ' ' || line[i] == '\n') { // whitespace detection
            // get number by getting numStartPos up to this point
            string temp = line.substr(numStartPos, i - numStartPos);
            num = stod(temp); // convert to double
            grid[currentRow][currentCol] = num; // set grid location to num
            ++currentCol;
            numStartPos = i + 1; // reset position to the one after the space char
        }
        // make sure to get the last num if any characters left at the end
        else if (i == line.size() - 1) {

            string temp = line.substr(numStartPos, i - numStartPos + 1);
            num = stod(temp);
            grid[currentRow][currentCol] = num;

        }
    }
    ++currentRow;
    
}