// COMSC-210-5293 | Lab 13 | Yuyi Chen

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 150;

// Store each student's ID and exam score
struct Student {
    int id;
    double score;
};

// Function prototype
void selectionSort(Student[], int);
Student findMinimum(Student[], int);
Student findMaximum(Student[], int);

int main() {
    Student students[SIZE];

    // Open the file that contains the student grades
    ifstream fin;
    fin.open("210-lab-13-grades.txt");

    // Stop the program if the input file cannot be opened
    if (!fin) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    // Read each student's ID and score into the array
    for (int i = 0; i < SIZE; i++) {
        fin >> students[i].id >> students[i].score;
    }

    fin.close();

    // Sort the student records by student ID
    selectionSort(students, SIZE);
    // Get the minimum
    Student minimumStudent = findMinimum(students, SIZE);
    // Get the maximum
    Student maximumStudent = findMaximum(students, SIZE);

    // Open a new file for the sorted student records
    ofstream fout;
    fout.open("210-lab-13-grades-sorted.txt");

    // Stop the program if the output file cannot be opened
    if (!fout) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    // Write the sorted student records to the output file
    for (int i = 0; i < SIZE; i++) {
        fout << students[i].id << " " << students[i].score << endl;
    }

    fout.close();

    cout << "Minimum Score: " << minimumStudent.score
         << " (Student ID: " << minimumStudent.id << ")" << endl;

    cout << "Maximum Score: " << maximumStudent.score
         << " (Student ID: " << maximumStudent.id << ")" << endl;

    return 0;
}

// selectionSort() sorts students by ID from smallest to largest
// arguments: array of Student records and array size
// returns: nothing
void selectionSort(Student students[], int size) {
    int indexSmallest;

    for (int i = 0; i < size - 1; i++) {
        indexSmallest = i;

        // Find the smallest student ID in the remaining array
        for (int j = i + 1; j < size; j++) {
            if (students[j].id < students[indexSmallest].id) {
                indexSmallest = j;
            }
        }

        // Swap the whole student record
        Student temp = students[i];
        students[i] = students[indexSmallest];
        students[indexSmallest] = temp;
    }
}

// findMinimum() finds the student with the lowest exam score
// arguments: array of Student records and array size
// returns: Student record with the minimum score
Student findMinimum(Student students[], int size) {
    Student minimumStudent = students[0];

    for (int i = 1; i < size; i++) {
        if (students[i].score < minimumStudent.score) {
            minimumStudent = students[i];
        }
    }

    return minimumStudent;
}

// findMaximum() finds the student with the highest exam score
// arguments: array of Student records and array size
// returns: Student record with the maximum score
Student findMaximum(Student students[], int size) {
    Student maximumStudent = students[0];

    for (int i = 1; i < size; i++) {
        if (students[i].score > maximumStudent.score) {
            maximumStudent = students[i];
        }
    }

    return maximumStudent;
}