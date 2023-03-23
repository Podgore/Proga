#include <fstream>
#include <iostream>
#include <cstring>
#include "MainLibPointer.h"
using namespace std;

bool IsLatin(char* word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (!isalpha(word[i]) || !isascii(word[i]) || !islower(word[i]))
        {
            return false;
        }
    }
    return true;
}
void RemoveLatinWords(char* filename)
{
    FILE* inFile;
    if (fopen_s(&inFile, filename, "r") != 0)
    {
        cout << "Can't open a file" << endl;
        return;
    }

    FILE* outFile;
    if (fopen_s(&outFile, "temp.txt", "w") != 0)
    {
        cout << "Can't open a file" << endl;
        fclose(inFile);
        return;
    }

    char word[256];
    while (fscanf_s(inFile, "%s", word, (unsigned)_countof(word)) != EOF)
    {
        if (!IsLatin(word))
        {
            fprintf_s(outFile, "%s ", word);
        }
    }

    fclose(inFile);
    fclose(outFile);

    remove(filename);
    rename("temp.txt", filename);
}