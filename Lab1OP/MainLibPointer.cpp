#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int CalculateCof(char* line, int k)
{
    int cof = 0;
    int len = strlen(line);
    if (len % k != 0)
    {
        cof = (len / k) + 1;
    }
    else
    {
        cof = len / k;
    }
    return cof;
}

char** CreateSubstringsPS(char* line, int k, int cof, int diff)
{
    char** substr = new char* [cof];
    for (int i = 0; i < cof; i++)
    {
        substr[i] = new char[k];
    }
    
    int count = 0;
    for (int i = 0; i < cof; i++)
    {
        if (i != cof - 1 || strlen(line) % k == 0)
        {
            for (int j = k - 1; j >= 0; j--)
            {
                substr[i][j] = line[count];
                count++;
            }
        }
        else
        {
            //count--;
            for (int j = k - 1; j >= 0; j--)
            {
               // if (count < strlen(line))
                //{
                    substr[i][j] = line[count];
                //}
                count++;
            }
        }
    }
    return substr;
}

void WriteToFile(FILE* file_out, char* line, char** substr, int k, int cof)
{
    if (file_out != NULL)
    {
        int count = 0;
        for (int i = 0; i < cof; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (count < strlen(line))
                {
                    line[count] = substr[i][j];
                }
                    count++;
            }
        }
        fprintf(file_out, "%s\n", line);
    }
    else 
    {
        cout << "File cant be edited";
    }
}

void PrintSubstringsP(char** substr, int k, int cof)
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

void EncryptFile(int k, char* filename, char* filename1)
{
    char* line = new char[1000];
    FILE* file_edit;
    FILE* file_out;
    int err = fopen_s(&file_edit, filename, "r");
    if (err != 0 || !file_edit)
    {
        cout << "Failed to open file: " << filename << endl;
        return;
    }
    err = fopen_s(&file_out, filename1, "w");
    if (err != 0 || !file_out)
    {
        cout << "Failed to create file: NewText.txt" << endl;
        fclose(file_edit);
        return;
    }

    cout << "---------------------------------------------------------------------------------------------------------------------\n";
    cout << "File before remove only latins words:\n";
    while (fgets(line, 1000, file_edit))
    {
        int diff = k - (strlen(line) % k);
        int cof = CalculateCof(line, k);
        char** substr = CreateSubstringsPS(line, k, cof, diff);
        WriteToFile(file_out, line, substr, k, cof);

        PrintSubstringsP(substr, k, cof);
        for (int i = 0; i < cof; i++)
        {
            delete[] substr[i];
        }
        delete[] substr;
    }
    fclose(file_out);
    fclose(file_edit);
    delete[] line;
}