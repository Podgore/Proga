#pragma once
#include <iostream>
#include <string>

using namespace std;

class Train {
private:
    int ID;
    string LastStage;
    int Hours;
    int Minutes;
public:
    Train(int ID, string LastStage, int Hours, int Minutes);
    Train();

    int GetHours();
    int GetMinutes();
    string GetLastStage();
    int GetID();
};

