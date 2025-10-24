#include <iostream>
#include <cstdlib>
using namespace std;

int cmp;

int partition(int a[], int l, int h, int pivotType) {
    int pivotIndex;
    if (pivotType == 1) pivotIndex = l;
    else if (pivotType == 2) pivotIndex = l + rand() % (h - l + 1);
    else if (pivotType == 3) pivotIndex = (l + h) / 2;
    else {
        int mid = (l + h) / 2;
        int arr[3] = {a[l], a[mid], a[h]};
        if ((arr[0] > arr[1]) != (arr[0] > arr[2])) pivotIndex = l;
        else if ((arr[1] > arr[0]) != (arr[1] > arr[2])) pivotIndex = mid;
        else pivotIndex = h;
    }
    int pivot = a[pivotIndex];
    swap(a[pivotIndex], a[h]);
    int i = l - 1;
    for (int j = l; j < h; j++) {
        cmp++;
        if (a[j] < pivot) { i++; swap(a[i], a[j]); }
    }
    swap(a[i + 1], a[h]);
    return i + 1;
}

void quickSort(int a[], int l, int h, int pivotType) {
    if (l < h) {
        int p = partition(a, l, h, pivotType);
        quickSort(a, l, p - 1, pivotType);
        quickSort(a, p + 1, h, pivotType);
    }
}

int main() {
    int a[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int n = 9;
    for (int t = 1; t <= 4; t++) {
        int arr[9];
        for (int i = 0; i < n; i++) arr[i] = a[i];
        cmp = 0;
        quickSort(arr, 0, n - 1, t);
        cout << "Pivot " << t << " comparisons: " << cmp << endl;
    }
    return 0;
}
