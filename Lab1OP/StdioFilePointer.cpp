#include <fstream>
#include <iostream>
#include <cstring>
#include "MainLibPointer.h"
using namespace std;

void ReadFile(char* filename)
{
    char* line = new char[256];

    FILE* file_in;
    if (fopen_s(&file_in, filename, "r") == 0)
    {
        while (fgets(line, 100, file_in))
        {
            cout << line << endl;

        }
        fclose(file_in);
    }
}

char* CreatFile(char* filename)
{
    char* input_text = new char[256];
    FILE* file_create;
    if (fopen_s(&file_create, filename, "w") == 0)
    {
        cout << "Enter text (type 'exit' to stop):\n";
        
        while (fgets(input_text, 256, stdin))
        {
            if (strcmp(input_text, "exit\n") == 0)
            {
                break;
            }
            fputs(input_text, file_create);
        }
        
        fclose(file_create);
        cout << "File created successfully: " << filename << endl;
    }
    else
    {
        cout << "File can't be created";
    }
    return input_text;
}

void AppendToFile(char* filename, char* input_text)
{
    FILE* file_append;
    if (fopen_s(&file_append, filename, "a") == 0)
    {
        cout << "Enter text (type 'exit' to stop):\n";
        char* input_text_up = new char[256];
        fputs(input_text, file_append);
        while (fgets(input_text_up, 256, stdin))
        {
            if (strcmp(input_text_up, "exit\n") == 0)
            {
                break;
            }
            fputs(input_text_up, file_append);
        }
        fclose(file_append);
        delete[] input_text_up;
        cout << "Text added to file successfully: " << filename << endl;
    }
    else
    {
        cout << "File can't be opened" << endl;
    }
}