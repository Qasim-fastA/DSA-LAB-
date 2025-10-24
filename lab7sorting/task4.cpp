#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name, desc;
    float price;
    bool available;
};

int partition(Product a[], int l, int h) {
    float pivot = a[h].price;
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (a[j].price < pivot) {
            i++;
            Product t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    Product t = a[i + 1];
    a[i + 1] = a[h];
    a[h] = t;
    return i + 1;
}

void quickSort(Product a[], int l, int h) {
    if (l < h) {
        int p = partition(a, l, h);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, h);
    }
}

int main() {
    Product p[3];
    for (int i = 0; i < 3; i++) {
        cout << "Enter name: ";
        cin >> p[i].name;
        cout << "Enter price: ";
        cin >> p[i].price;
        cout << "Enter description: ";
        cin >> p[i].desc;
        cout << "Enter availability (1/0): ";
        cin >> p[i].available;
    }
    quickSort(p, 0, 2);
    for (int i = 0; i < 3; i++)
        cout << p[i].name << " " << p[i].price << " " << p[i].desc << " " << p[i].available << endl;
    return 0;
}
