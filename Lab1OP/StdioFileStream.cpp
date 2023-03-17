#include <fstream>
#include <iostream>
#include <string>
#include "MainLibStream.h"
using namespace std;


void ReadFile(string filename)
{
    string line;
    int LinesNumbers = 0;
    ifstream file_in(filename);
    if (file_in.is_open())
    {
        while (getline(file_in, line))
        {
            cout << line << endl;
            LinesNumbers++;
        }
        file_in.close();
    }
}

string CreatFile(string filename)
{
    string input_text;
    ofstream file_create(filename);
    if (file_create.is_open())
    {
        cout << "Enter text (type 'exit' to stop):\n";
        
        while (getline(cin, input_text))
        {
            if (input_text == "exit")
            {
                break;
            }
            file_create << input_text << endl;
        }
        file_create.close();
        cout << "File created successfully: " << filename << endl;
    }
    else
    {
        cout << "File can't be created";
    }

    return input_text;
}

void AppendToFile(string filename, string input_text)
{
    ofstream file_append;
    file_append.open(filename, ios::app);
    if (file_append.is_open())
    {
        cout << "Enter text (type 'exit' to stop):\n";
        string input_text_up;
        while (getline(cin, input_text_up))
        {
            if (input_text_up == "exit")
            {
                break;
            }
            file_append << input_text << endl;
            file_append << input_text_up << endl;
        }
        file_append.close();
        cout << "Text added to file successfully: " << filename << endl;
    }
    else
    {
        cout << "File can't be opened";
    }
}