// Program 3 of selection and repititon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to merge two files based on the key field
void mergeFiles(const string& inputFile1, const string& inputFile2, const string& outputFile) {
    ifstream file1(inputFile1);
    ifstream file2(inputFile2);
    ofstream mergedFile(outputFile);

    string line1, line2;

    // Read initial lines from both files
    getline(file1, line1);
    getline(file2, line2);

    while (!file1.eof() && !file2.eof()) {
        // Extract the key (student name) from each line
        string key1 = line1.substr(0, line1.find(' '));
        string key2 = line2.substr(0, line2.find(' '));

        if (key1 < key2) {
            mergedFile << line1 << endl;
            getline(file1, line1);
        }
        else {
            mergedFile << line2 << endl;
            getline(file2, line2);
        }
    }

    // Write remaining lines from both files
    while (!file1.eof()) {
        mergedFile << line1 << endl;
        getline(file1, line1);
    }
    while (!file2.eof()) {
        mergedFile << line2 << endl;
        getline(file2, line2);
    }

    cout << "Merged data written to " << outputFile << endl;
}

int main() {
    string inputFile1 = "TextFile1.txt"; 
    string inputFile2 = "TextFile2.txt";
    string outputFile = "output.txt";

    mergeFiles(inputFile1, inputFile2, outputFile);

    return 0;
}