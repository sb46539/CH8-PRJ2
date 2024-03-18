// This program collets data for marathon runners such as names, average miles, and total miles in a text file. It reads the data and runs the necessary calculations.
// It displays a table with name, total miles, and average miles.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int numRunners = 5;
const int numDays = 7;

struct Runner {
    string name;
    float miles[numDays];
    float total;
    float avg;
};

// preconds: names and miles arrays are allocated, postconds: reads runner data from text file into arrays
void readRunnerData(Runner runners[]) {
    ifstream inputFile("C:/Users/sb0s/source/repos/runners.txt");

    for (int i = 0; i < numRunners; i++) {
        inputFile >> runners[i].name;
        for (int j = 0; j < numDays; j++) {
            inputFile >> runners[i].miles[j];
        }
    }

    inputFile.close();
}
// preconds: names, miles, total, avg arrays are allocated, postconds: calculates total and average miles
void calculateTotal(Runner runners[]) {
    for (int i = 0; i < numRunners; i++) {
        runners[i].total = 0;
        for (int j = 0; j < numDays; j++) {
            runners[i].total += runners[i].miles[j];
        }
        runners[i].avg = runners[i].total / numDays;
    }
}

// preconds: names, miles, total, avg arrays are allocated, postconds: prints a formatted table displaying runner data
void printRunnerData(const Runner runners[]) {
    cout << setw(15) << left << "Runner's name";
    cout << setw(15) << right << "Total miles";
    cout << setw(15) << right << "Average miles" << endl;
    cout << setfill('-') << setw(45) << "-" << setfill(' ') << endl;

    for (int i = 0; i < numRunners; i++) {
        cout << setw(15) << left << runners[i].name;
        cout << setw(15) << right << fixed << setprecision(2) << runners[i].total;
        cout << setw(15) << right << fixed << setprecision(2) << runners[i].avg << endl;
    }
}

int main() {
    Runner runners[numRunners];

    readRunnerData(runners);
    calculateTotal(runners);
    printRunnerData(runners);

    return 0;
}
