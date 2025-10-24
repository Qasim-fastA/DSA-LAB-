#include <iostream>
using namespace std;

int getMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) if (a[i] > mx) mx = a[i];
    return mx;
}

void countingSort(int a[], int n, int exp, bool asc) {
    int output[1000], count[10] = {0};
    for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int idx = (a[i] / exp) % 10;
        output[--count[idx]] = a[i];
    }
    if (!asc) for (int i = 0; i < n / 2; i++) swap(output[i], output[n - i - 1]);
    for (int i = 0; i < n; i++) a[i] = output[i];
}

void radixSort(int a[], int n, bool asc) {
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10) countingSort(a, n, exp, asc);
}

int main() {
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
    radixSort(a, n, true);
    cout << "Ascending: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    radixSort(a, n, false);
    cout << "Descending: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
