#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int CalculateCof(string line, int k);


char** CreateSubstrings(string line, int k, int cof, int diff);


void WriteToFile(ofstream& file_out, string line, char** substr, int k, int cof);

void PrintSubstrings(char** substr, int k, int cof);

void EncryptFile(int k, string filename);

