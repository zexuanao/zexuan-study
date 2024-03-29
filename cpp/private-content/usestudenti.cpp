#include <iostream>
#include "studenti.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main() {
    Student ada[pupils] = {
        Student(quizzes),
        Student(quizzes),
        Student(quizzes)
    };

    for (int i = 0; i < pupils; i++)
        set(ada[i], quizzes);

    cout << "Student List:\n";
    for (int i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;

    cout << "\nResults:\n";
    for (int i = 0; i < pupils; i++)
        cout << ada[i] << endl << "Average: " << ada[i].Average() << endl;

    cout << "Done.\n";
    return 0;
}

void set(Student & sa, int n) {
    cout << "Please enter the student's name: ";
    getline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n')
        continue;
}
