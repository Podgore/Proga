
#include <fstream>
#include <iostream>
#include <string>
using namespace std;



int CalculateCof(char* line, int k);


char** CreateSubstringsPS(char* line, int k, int cof, int diff);


void EncryptFile(int k, char* filename, char* filename1);

void PrintSubstringsP(char** substr, int k, int cof);

void WriteToFile(FILE* file_out, char* line, char** substr, int k, int cof);


