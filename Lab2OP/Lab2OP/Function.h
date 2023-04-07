#include <fstream>
#include <iostream>

using namespace std;

void GetUserTime(tm& time);

double CalculateCost(tm& start_time, tm& end_time);

void WriteCallToFile(ofstream& file, tm& start_time, tm& end_time, double cost);

void PrintCallDetails(tm& start_time, tm& end_time, double cost);

void AddCall();

void ReadCallsFromFile();