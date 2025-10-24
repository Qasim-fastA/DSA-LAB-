#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int time;
};

void merge(Runner a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Runner L[50], R[50];
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(Runner a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    Runner r[10];
    for (int i = 0; i < 10; i++) {
        cout << "Enter name: ";
        cin >> r[i].name;
        cout << "Enter time: ";
        cin >> r[i].time;
    }
    mergeSort(r, 0, 9);
    cout << "Top 5 fastest:\n";
    for (int i = 0; i < 5; i++) cout << r[i].name << " " << r[i].time << endl;
    return 0;
}
