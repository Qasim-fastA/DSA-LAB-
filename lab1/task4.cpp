#include <iostream>
#include <string>
using namespace std;

class Product {
    string name;
    double price;
    int stock;
public:
    Product(string n = "", double p = 0.0, int s = 0) {
        name = n;
        price = p;
        stock = s;
    }
    void applyDiscount(double percent) {
        price = price - (price * percent / 100);
    }
    void display() {
        cout << "Product: " << name << ", Price: " << price << ", Stock: " << stock << endl;
    }
};

class Bundle {
    Product** products;
    int size;
    int capacity;
    double discount;
public:
    Bundle(int cap = 5, double d = 0) {
        capacity = cap;
        size = 0;
        discount = d;
        products = new Product*[capacity];
    }
    Bundle(const Bundle &obj) { 
        discount = obj.discount;
        size = obj.size;
        capacity = obj.capacity;
        products = obj.products; 
    }
    Bundle* deepCopy() {
        Bundle* copy = new Bundle(capacity, discount);
        copy->size = size;
        for (int i = 0; i < size; i++) {
            copy->products[i] = new Product(*products[i]);
        }
        return copy;
    }
    void addProduct(Product* p) {
        if (size < capacity) {
            products[size] = p;
            size++;
        }
    }
    void applyDiscount() {
        for (int i = 0; i < size; i++) {
            products[i]->applyDiscount(discount);
        }
    }
    void display() {
        cout << "Bundle discount: " << discount << "%" << endl;
        for (int i = 0; i < size; i++) {
            products[i]->display();
        }
    }
    ~Bundle() {
    }
};

int main() {
    Product* p1 = new Product("Laptop", 1000, 5);
    Product* p2 = new Product("Phone", 500, 10);

    Bundle b1(5, 10);
    b1.addProduct(p1);
    b1.addProduct(p2);

    cout << "Original Bundle (b1):" << endl;
    b1.display();

    Bundle b2 = b1; 
    Bundle* b3 = b1.deepCopy(); 

    b1.applyDiscount();

    cout << "\nAfter applying discount to b1:" << endl;
    cout << "b1 details:" << endl;
    b1.display();

    cout << "b2 (shallow copy) details:" << endl;
    b2.display();

    cout << "b3 (deep copy) details:" << endl;
    b3->display();

    delete b3;
    return 0;
}
