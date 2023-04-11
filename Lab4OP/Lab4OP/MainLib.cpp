#include <iostream>
#include "Time.h"

using namespace std;



Time PrintTime() {
    int Minutes = 0;
    int Hours = 0;
    int Seconds = 0;
    
    cin >> Hours >> Minutes >> Seconds;
    Time inputTime1(Hours, Minutes, Seconds);
    inputTime1.PrintTime();
    return inputTime1;
}

void CompareTime(Time time1, Time time2) {
    bool comperence = time1 < time2;

    if (comperence) {
        cout << "T1 < T2" << endl;
    }
    else {
        cout << "T1 > T2" << endl;
    }
}
