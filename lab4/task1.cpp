#include <iostream>
using namespace std;

int main() {
    int arr[10];
    cout << "Enter 10 numbers:\n";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    
    for (int i = 0; i < 10 - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < 10; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "The 4 smallest numbers are: ";
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
