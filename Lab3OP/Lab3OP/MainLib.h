#include <iostream>
#include <string>
#include "Train.h"

using namespace std;



void GetTime(string Time, int& Hours, int& Minutes);
void BubbleSort(Train* train, int amount);
void fillTrainArray(Train* train, int amount);
void printLatestTrain(Train* train, int amount);