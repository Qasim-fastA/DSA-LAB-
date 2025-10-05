#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "How many IDs? ";
    cin >> n;

    int *ids = new int[n];
    cout << "Enter " << n << " IDs:\n";
    for (int i = 0; i < n; i++)
        cin >> ids[i];

    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (ids[j] < ids[minIndex])
                minIndex = j;
        }
        int temp = ids[i];
        ids[i] = ids[minIndex];
        ids[minIndex] = temp;
    }

    cout << "Sorted IDs:\n";
    for (int i = 0; i < n; i++)
        cout << ids[i] << " ";
    cout << endl;

    delete[] ids;
    return 0;
}
