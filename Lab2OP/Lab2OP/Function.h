#include <fstream>
#include <iostream>

using namespace std;

void get_user_time(tm& time);

double calculate_cost(tm& start_time, tm& end_time);

void write_call_to_file(ofstream& file, tm& start_time, tm& end_time, double cost);

void print_call_details(tm& start_time, tm& end_time, double cost);