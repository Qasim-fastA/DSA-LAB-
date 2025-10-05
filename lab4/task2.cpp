#include <iostream>
using namespace std;

int main() {
    int arr[9] = {20, 12, 15, 2, 10, 1, 13, 9, 5};

    
    for (int i = 1; i < 9; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    int maxVal = arr[8];        
    for (int i = 8; i > 4; i--)  
        arr[i] = arr[i - 1];
    arr[4] = maxVal;

    cout << "Sorted array with max in middle:\n";
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
