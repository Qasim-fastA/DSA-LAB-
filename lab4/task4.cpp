#include <iostream>
using namespace std;

bool hasDuplicate(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (hasDuplicate(a, n))
        cout << "Array has duplicates\n";
    else
        cout << "Array has no duplicates\n";
    delete[] a;
    return 0;
}
