#include <fstream>
#include <iostream>
#include <string>
#include "MainLibStream.h"
using namespace std;

bool IsLatin(string word)
{
    for (char c : word)
    {
        if (!isalpha(c) || !isascii(c) || !islower(c))
        {
            return false;
        }
    }
    return true;
}

void RemoveLatinWords(string filename)
{
    ifstream inFile(filename);
    ofstream outFile("temp.txt");

    if (!inFile || !outFile)
    {
        cout << "Can't open a file" << endl;
        return;
    }

    string word;
    while (inFile >> word)
    {
        if (!IsLatin(word))
        {
            outFile << word << " ";
        }
    }

    inFile.close();
    outFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}
