#include <iostream>
#include <fstream>
#include <ctime>
#include "Function.h"

using namespace std;

int main()
{
    ofstream file("calls.bin", ios::binary);
    int amount;
    time_t now = time(nullptr);
    cout << "Type an amount of calls" << endl;
    cin >> amount;
    for (int i = 0; i < amount; i++) {
        tm start_time;
        get_user_time(start_time);

        tm end_time;
        get_user_time(end_time);

        double cost = calculate_cost(start_time, end_time);

        write_call_to_file(file, start_time, end_time, cost);

        print_call_details(start_time, end_time, cost);
    }

    file.close();
    return 0;
}