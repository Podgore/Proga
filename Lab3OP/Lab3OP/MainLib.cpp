#include <iostream>
#include <string>
#include "Train.h"

using namespace std;

void GetTime(string time, int& hours, int& minutes) {
    string delimiter = "-";
    size_t pos = 0;
    string token;
    int i = 0;
    while ((pos = time.find(delimiter)) != string::npos) {
        token = time.substr(0, pos);
        if (i == 0) {
            hours = stoi(token);
        }
        else if (i == 1) {
            minutes = stoi(token);
        }
        time.erase(0, pos + delimiter.length());
        i++;
    }
    minutes = stoi(time);
}

void BubbleSort(Train* train, int amount) {
    for (int i = 0; i < amount - 1; i++) {
        for (int j = 0; j < amount - i - 1; j++) {
            if (train[j].GetHours() < train[j + 1].GetHours()) {
                swap(train[j], train[j + 1]);
            }
            else if (train[j].GetHours() == train[j + 1].GetHours() && train[j].GetMinutes() < train[j + 1].GetMinutes()) {
                swap(train[j], train[j + 1]);
            }
        }
    }
}

void fillTrainArray(Train* train, int amount) {
    int ID = 0;
    int Hours = 0;
    int Minutes = 0;
    string LastStage, Time;

    for (int i = 0; i < amount; i++) {
        cout << "Enter ID " << i + 1 <<": ";
        cin >> ID;
        cout << "Enter LastStage " << i + 1 << ": ";
        cin >> LastStage;
        cout << "Enter Time "<< i + 1<< "(in format HH - MM): ";
        cin >> Time;
        GetTime(Time, Hours, Minutes);

        train[i] = Train(ID, LastStage, Hours, Minutes);
    }
}

void printLatestTrain(Train* train, int amount) {
    BubbleSort(train, amount);
    cout << "Latest train: " << train[0].GetID() << "\t" << train[0].GetLastStage() << "\t" << train[0].GetHours() << "-" << train[0].GetMinutes() << endl;
}