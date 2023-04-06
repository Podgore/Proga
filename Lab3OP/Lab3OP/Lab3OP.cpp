#include <iostream>
#include <string>
#include "Train.h"
#include "MainLib.h"

using namespace std;


int main()
{
    int amount = 0;
    cout << "Type amount of objects" << endl;
    cin >> amount;

    Train* train = new Train[amount];
    fillTrainArray(train, amount);
    printLatestTrain(train, amount);

    delete[] train;
    return 0;
}


