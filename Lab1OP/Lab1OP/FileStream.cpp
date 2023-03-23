#include <fstream>
#include <iostream>
#include <string>
#include "MainLibStream.h"
#include "LatinStream.h"
#include "StdioFileStream.h"
using namespace std;


void FileStream ()
{
	int k;
	int choice;
	string input_text;
	string filename;
	string filename1 = "NewText.txt";

	setlocale(LC_ALL, "UA");

	cout << "Enter filename:\n";
	cin >> filename;
	CreatFile(filename);
	cout << "Enter k:\n";

	cin >> k;
	cout << "---------------------------------------------------------------------------------------------------------------------\n";
	cout << "File before editing:\n";
	ReadFile(filename);
	EncryptFile(k, filename);
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
		EncryptFile(k, filename);
		RemoveLatinWords(filename1);
		cout << "---------------------------------------------------------------------------------------------------------------------\n";
		cout << "File after removing only latins word:\n";
		ReadFile(filename1);
	}
	else 
	{

	}
}

