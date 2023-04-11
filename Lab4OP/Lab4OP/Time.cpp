#include <iostream>
#include "Time.h"
using namespace std;


Time::Time(int Hours, int Minutes, int Seconds)
{
    this->Hours = Hours;
    this->Minutes = Minutes;
    this->Seconds = Seconds;
}

Time::Time(int Hours, int Minutes)
{
    this->Hours = Hours;
    this->Minutes = Minutes;
    this->Seconds = 00;
}

Time::Time(int Hours)
{
    this->Hours = Hours;
    this->Minutes = 00;
    this->Seconds = 00;
}

int Time::GetHours() {
    return Hours;
}

int Time::GetMinutes() {
    return Minutes;
}

int Time::GetSeconds() {
    return Seconds;
}

int Time::operator ++() {
    return ++Minutes;
}

int Time::operator ++(int) {
    return ++Seconds;
}
Time Time::operator -(const Time& other) {

    int seconds = Seconds - other.Seconds;
    int minutes = Minutes - other.Minutes;
    int hours = Hours - other.Hours;

    if (seconds < 0) {
        seconds += 60;
        minutes--;
    }

    if (minutes < 0) {
        minutes += 60;
        hours--;
    }

    Time timeResult(hours, minutes, seconds);
    return timeResult;
}

bool Time::operator < (const Time& time) const
{
    if (Hours < time.Hours) {
        return true;
    }
    else if (Minutes < time.Minutes && Hours == time.Hours) {
        return true;
    }
    else if (Seconds < time.Seconds && Hours == time.Hours && Minutes == time.Minutes) {
        return true;
    }
    else {
        return false;
    }
}

void Time::PrintTime() {
    cout << "Time: " << Hours << ":" << Minutes << ":" << Seconds << endl;
}

void Time::PrintTimeAfter() {
    cout << "Time After Manipulation: " << Hours << ":" << Minutes << ":" << Seconds << endl;
}