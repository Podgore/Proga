#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int CalculateCof(string line, int k)
{
    int dif = 0;
    int cof = 0;
    if (line.length() % k != 0)
    {
        dif = k - (line.length() % k);
        cof = (line.length() / k) + 1;
    }
    else
    {
        cof = line.length() / k;
    }
    if (dif >= k)
    {
        dif = 0;
    }
    return cof;
}

char** CreateSubstrings(string line, int k, int cof, int diff)
{
    char** substr = new char* [cof];
    for (int i = 0; i < cof; i++)
    {
        substr[i] = new char[k];
    }
    int counter = 0;
    int count = 0;
    for (int i = 0; i < cof; i++)
    {
        if (i != cof - 1 || line.length() % k == 0)
        {
           counter += k;
            for (int j = k - 1; j >= 0; j--)
            {
                substr[i][j] = line[count];
                count++;
            }
        }
        else
        {
           count--;
           counter += diff;
            for (int j = k - 1; j >= 0; j--)
            {
               if (count < line.length())
                {
                    substr[i][j] = line[count];
                }
                count++;
            }
        }
    }
    return substr;
}

void WriteToFile(ofstream& file_out, string line, char** substr, int k, int cof)
{
    if (file_out.is_open())
    {
        int count = 0;
        for (int i = 0; i < cof; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (count < line.length())
                {
                    line[count] = substr[i][j];
                }

                count++;
            }
        }
         file_out << line << endl;     
    }
    else {
        cout << "File cant be edited";
    }
}

void PrintSubstrings(char** substr, int k, int cof)
{

    for (int i = 0; i < cof; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << substr[i][j];
        }
    }
    cout << endl;
}

void EncryptFile(int k, string filename)
{
    string line;
    ifstream file_edit(filename);
    ofstream file_out("NewText.txt");
    cout << "---------------------------------------------------------------------------------------------------------------------\n";
    cout << "File before remove only latins words:\n";
    while (getline(file_edit, line))
    {
        int diff = k - (line.length() % k);
        int cof = CalculateCof(line, k);
        char** substr = CreateSubstrings(line, k, cof, diff);
        WriteToFile(file_out, line, substr, k, cof);

        PrintSubstrings(substr, k, cof);
        for (int i = 0; i < cof; i++)
        {
            delete[] substr[i];
        }
        delete[] substr;
    }
    file_out.close();
    file_edit.close();
}


