#include <fstream>
#include <iostream> 
#include <ctime>
#include "Function.h"
using namespace std;

void get_user_time(tm& time) {
    int year, month, day, hour, minute, second;
    cout << "Enter the time of begining and ending (YYYY MM DD HH MM SS): ";
    cin >> year >> month >> day >> hour >> minute >> second;
    time.tm_year = year - 1900;
    time.tm_mon = month - 1;
    time.tm_mday = day;
    time.tm_hour = hour;
    time.tm_min = minute;
    time.tm_sec = second;
}

double calculate_cost(tm& start_time, tm& end_time) {
    double price_per_minute = 0.0;
    if (start_time.tm_hour >= 22 || start_time.tm_hour < 7) {
        price_per_minute = 0.0;
    }
    else if (start_time.tm_hour >= 9 && start_time.tm_hour < 18) {
        price_per_minute = 1.7;
    }
    else {
        price_per_minute = 1.19;
    }

    double duration = difftime(mktime(&end_time), mktime(&start_time)) / 60.0;
    double cost = duration * price_per_minute;

    return cost;
}


void write_call_to_file(ofstream& file, tm& start_time, tm& end_time, double cost) {
    file.write((char*)&start_time, sizeof(start_time));
    file.write((char*)&end_time, sizeof(end_time));
    file.write((char*)&cost, sizeof(cost));
}

void print_call_details(tm& start_time, tm& end_time, double cost) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%c", &start_time);
    cout << "Data start: " << buffer << endl;
    strftime(buffer, sizeof(buffer), "%c", &end_time);
    cout << "Data end: " << buffer << endl;
    cout << "Cost: " << cost << "$" << endl;
}
