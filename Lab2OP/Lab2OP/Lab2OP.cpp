#include <iostream>
#include <fstream>
#include <ctime>
#include "Function.h"

using namespace std;

int main()
{
    char answer;
    do {
        AddCall();
        ReadCallsFromFile();
        cout << "Do you want to add another call? (y/n)" << endl;
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    return 0;
}