#pragma once


class Time {
private:
    int Hours;
    int Minutes;
    int Seconds;
public:

    Time() {};
    Time(int Hours, int Minutes, int Seconds);
    Time(int Hours, int Minutes);
    Time(int Hours);

    int GetHours();
    int GetMinutes();
    int GetSeconds();

    int operator ++();
    int operator ++(int);
    Time operator -(const Time& other);
    bool operator < (const Time& time) const;

    void PrintTime();
    void PrintTimeAfter();
};
