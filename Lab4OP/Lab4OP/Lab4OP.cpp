#include <iostream>
#include "Time.h"
#include "MainLib.h"
using namespace std;


int main()
{
    cout << "Enter T" << 1 << "(in format HH MM SS):" << endl;
    Time time1 = PrintTime();
    cout << "Enter T" << 2 << "(in format HH MM SS):" << endl;
    Time time2 = PrintTime();;
   

    ++time1;
    time2++;
    
    time1.PrintTimeAfter();
    time2.PrintTimeAfter();

    CompareTime(time1, time2);
    cout << "Enter T" << 3 << "(in format HH MM SS):" << endl;
    Time time3 = PrintTime();
    cout << "Enter Time of End(in format HH MM SS):" << endl;
    Time timeEnd = PrintTime();


    Time timeResult = timeEnd - time3;
    timeResult.PrintTimeAfter();

}

