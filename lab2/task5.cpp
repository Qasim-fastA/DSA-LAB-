#include <iostream>
#include <string>
using namespace std;

int main() {
    string departments[4] = {"SE", "AI", "CS", "DS"};
    int numCourses[4] = {3, 4, 2, 1};
    float* gpas[4];

    for (int i = 0; i < 4; i++) {
        gpas[i] = new float[numCourses[i]];
    }

    for (int i = 0; i < 4; i++) {
        cout << "Enter GPAs for " << departments[i] << " department" << endl;
        for (int j = 0; j < numCourses[i]; j++) {
            cout << "Course " << j + 1 << ": ";
            cin >> gpas[i][j];
        }
    }

    cout << endl << "GPA Record:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << departments[i] << ": ";
        for (int j = 0; j < numCourses[i]; j++) {
            cout << gpas[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete[] gpas[i];
    }

    return 0;
}
