// COMSC-210-5293 | Lab 13 | Yuyi Chen

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 150;

struct Student {
    int id;
    double score;
};

int main() {
    Student students[SIZE];

    ifstream fin;
    fin.open("210-lab-13-grades.txt");

    if (!fin) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        fin >> students[i].id >> students[i].score;
    }

    fin.close();

    cout << students[9].id << " " << students[9].score << endl;

    return 0;
}