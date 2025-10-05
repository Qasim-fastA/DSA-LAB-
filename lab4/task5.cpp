#include <iostream>
using namespace std;

int main() {
    int arr[6] = {2022, 2023, 2024, 2022, 2023, 2024};
    int temp[6];
    int k = 0;

    for (int i = 0; i < 6; i++)
        if (arr[i] == 2022) temp[k++] = arr[i];
    for (int i = 0; i < 6; i++)
        if (arr[i] == 2023) temp[k++] = arr[i];
    for (int i = 0; i < 6; i++)
        if (arr[i] == 2024) temp[k++] = arr[i];

    cout << "Sorted years: ";
    for (int i = 0; i < 6; i++)
        cout << temp[i] << " ";
    cout << endl;
    return 0;
}
