#include <fstream>
#include <iostream>
#include <string>
#include "MainLibPointer.h"
#include "LatinPointer.h"
#include "StdioFilePointer.h"
using namespace std;


void FilePointer()
{
	int choice = 0;
	char* input_text = new char[256];
	char* filename = new char[256]; 
	char* filename1 = new char[256]; 

	int k;
	
	setlocale(LC_ALL, "UA");

	cout << "Enter filename:\n";
	cin >> filename;
	cout << "Enter filename of new file:\n";
	cin >> filename1;
	CreatFile(filename);
	cout << "Enter k:\n";

	cin >> k;
	cout << "---------------------------------------------------------------------------------------------------------------------\n";
	cout << "File before editing:\n";
	ReadFile(filename);
	EncryptFile(k, filename, filename1);
	RemoveLatinWords(filename1);
	cout << "---------------------------------------------------------------------------------------------------------------------\n";
	cout << "File after removing only latins word:\n";
	ReadFile(filename1);

	cout << "---------------------------------------------------------------------------------------------------------------------\n";
	cout << "Want to add some more text in file? 1)yep 2)no\n";
	cin >> choice;

	if (choice == 1)
	{
		AppendToFile(filename, input_text);
		cout << "---------------------------------------------------------------------------------------------------------------------\n";
		cout << "File before editing:\n";
		ReadFile(filename);
		EncryptFile(k, filename, filename1);
		RemoveLatinWords(filename1);
		cout << "---------------------------------------------------------------------------------------------------------------------\n";
		cout << "File after removing only latins word:\n";
		ReadFile(filename1);
	}
	else
	{

	}
	delete[] input_text;
	delete[] filename; 
	delete[] filename1;
}
