#include <iostream>
#include <string>
using namespace std;

int main() {
    int totalRows;
    cout << "Enter number of rows: ";
    cin >> totalRows;

    int* seats = new int[totalRows];
    string* chart[100];  // array of string pointers (jagged array)

    for (int i = 0; i < totalRows; i++) {
        cout << "Enter number of seats in row " << i + 1 << ": ";
        cin >> seats[i];
        chart[i] = new string[seats[i]];
    }

    cout << "\nEnter names of attendees:\n";
    for (int i = 0; i < totalRows; i++) {
        cout << "Row " << i + 1 << ":\n";
        for (int j = 0; j < seats[i]; j++) {
            cout << "  Seat " << j + 1 << ": ";
            cin >> chart[i][j];
        }
    }

    cout << "\nSeating Chart:\n";
    for (int i = 0; i < totalRows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < seats[i]; j++) {
            cout << chart[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < totalRows; i++) {
        delete[] chart[i];
    }
    delete[] seats;

    return 0;
}
