#include <fstream>
#include <iostream> 

#include "Function.h"
using namespace std;

void GetUserTime(tm& time) {
    int year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    time.tm_year = year - 1900;
    time.tm_mon = month - 1;
    time.tm_mday = day;
    time.tm_hour = hour;
    time.tm_min = minute;
    time.tm_sec = second;
}

double CalculateCost(tm& StartTime, tm& EndTime) {
    double price_per_minute = 0.0;
    if (StartTime.tm_hour >= 22 || StartTime.tm_hour < 7) {
        price_per_minute = 0.0;
    }
    else if (StartTime.tm_hour >= 9 && StartTime.tm_hour < 18) {
        price_per_minute = 1.7;
    }
    else {
        price_per_minute = 1.19;
    }

    double duration = difftime(mktime(&EndTime), mktime(&StartTime)) / 60.0;
    double cost = duration * price_per_minute;

    return cost;
}


void WriteCallToFile(ofstream& file, tm& StartTime, tm& EndTime, double cost) {
    file.write((char*)&StartTime, sizeof(StartTime));
    file.write((char*)&EndTime, sizeof(EndTime));
    file.write((char*)&cost, sizeof(cost));
}

void PrintCallDetails(tm& StartTime, tm& EndTime, double cost) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%c", &StartTime);
    cout << "Data start: " << buffer << endl;
    strftime(buffer, sizeof(buffer), "%c", &EndTime);
    cout << "Data end: " << buffer << endl;
    cout << "Cost: " << cost << "$" << endl;
}


void ReadCallsFromFile()
{
    string filename;
    cout << "Type a filename (in format text.bin): " << endl;
    cin >> filename;

    ifstream read_file(filename, ios::binary);
    if (!read_file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    while (true) {
        tm StartTime;
        tm EndTime;
        double cost;

        read_file.read((char*)&StartTime, sizeof(StartTime));
        read_file.read((char*)&EndTime, sizeof(EndTime));
        read_file.read((char*)&cost, sizeof(cost));

        if (read_file.eof()) {
            break;
        }

        PrintCallDetails(StartTime, EndTime, cost);
    }
    read_file.close();
}

void AddCall()
{
    string filename;
    cout << "Type a filename (in format text.bin): " << endl;
    cin >> filename;
    ofstream file(filename, ios::binary | ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    bool proceed = true;
    while (proceed) {
        tm startTime;
        cout << "Type the data of beginning(in format YYYY MM DD HH MM SS): ";
        GetUserTime(startTime);

        tm endTime;
        cout << "Type the data of ending(in format YYYY MM DD HH MM SS): ";
        GetUserTime(endTime);

        double cost = CalculateCost(startTime, endTime);

        WriteCallToFile(file, startTime, endTime, cost);

        PrintCallDetails(startTime, endTime, cost);

        cout << "Do you want to add another call? (y/n)" << endl;
        char answer;
        cin >> answer;
        proceed = (answer == 'y' || answer == 'Y');
    }
    file.close();
}
