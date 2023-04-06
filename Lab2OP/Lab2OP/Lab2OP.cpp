#include <iostream>
#include <fstream>
#include <ctime>
#include "Function.h"

using namespace std;

int main()
{
    ofstream file("calls.bin", ios::binary);
    int amount;
    time_t now = time(nullptr);
    cout << "Type an amount of calls" << endl;
    cin >> amount;
    
       for (int i = 0; i < amount; i++) {
            tm StartTime;
            GetUserTime(StartTime);

            tm EndTime;
            GetUserTime(EndTime);

            double cost = CalculateCost(StartTime, EndTime);

            WriteCallToFile(file, StartTime, EndTime, cost);

            PrintCallDetails(StartTime, EndTime, cost);
        }

    file.close();
    return 0;
}