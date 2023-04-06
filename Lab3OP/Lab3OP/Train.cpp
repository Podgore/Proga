#include "Train.h"
#include <iostream>
#include <string>

using namespace std;

Train::Train(int ID, string LastStage, int Hours, int Minutes) {
    this->ID = ID;
    this->LastStage = LastStage;
    this->Hours = Hours;
    this->Minutes = Minutes;
}

Train::Train() {}

int Train::GetHours() {
    return Hours;
}

int Train::GetMinutes() {
    return Minutes;
}

string Train::GetLastStage() {
    return LastStage;
}

int Train::GetID() {
    return ID;
}