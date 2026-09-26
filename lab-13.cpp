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

void selectionSort(Student[], int);

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

    selectionSort(students, SIZE);

    ofstream fout;
    fout.open("210-lab-13-grades-sorted.txt");

    if (!fout) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        fout << students[i].id << " " << students[i].score << endl;
    }

    fout.close();

    return 0;
}

void selectionSort(Student students[], int size) {
    int indexSmallest;

    for (int i = 0; i < size - 1; i++) {
        indexSmallest = i;

        for (int j = i + 1; j < size; j++) {
            if (students[j].id < students[indexSmallest].id) {
                indexSmallest = j;
            }
        }

        Student temp = students[i];
        students[i] = students[indexSmallest];
        students[indexSmallest] = temp;
    }
}