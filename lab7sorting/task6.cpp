#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[20], R[20];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int getMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) if (a[i] > mx) mx = a[i];
    return mx;
}

void countSort(int a[], int n, int exp) {
    int out[100], c[10] = {0};
    for (int i = 0; i < n; i++) c[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) out[--c[(a[i] / exp) % 10]] = a[i];
    for (int i = 0; i < n; i++) a[i] = out[i];
}

void radixSort(int a[], int n) {
    int m = getMax(a, n);
    for (int exp = 1; m / exp > 0; exp *= 10) countSort(a, n, exp);
}

int main() {
    int arr1[10], arr2[10], c[20];
    for (int i = 0; i < 10; i++) cin >> arr1[i];
    for (int i = 0; i < 10; i++) cin >> arr2[i];
    for (int i = 0; i < 10; i++) c[i] = arr1[i];
    for (int i = 0; i < 10; i++) c[10 + i] = arr2[i];
    cout << "Radix Sort: ";
    radixSort(c, 20);
    for (int i = 0; i < 20; i++) cout << c[i] << " ";
    cout << endl << "Merge Sort: ";
    mergeSort(c, 0, 19);
    for (int i = 0; i < 20; i++) cout << c[i] << " ";
    return 0;
}
