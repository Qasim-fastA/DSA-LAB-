#include <iostream>
using namespace std;

class Box {
    int *data;
public:
    Box(int val = 0) {
        data = new int(val);
    }

    
    Box(const Box &obj) {
        data = new int(*obj.data);
    }

    
    Box& operator=(const Box &obj) {
        if (this != &obj) {
            delete data;
            data = new int(*obj.data);
        }
        return *this;
    }

    void setValue(int val) {
        *data = val;
    }

    int getValue() {
        return *data;
    }

    ~Box() {
        delete data;
    }
};

int main() {
    
    Box b1(10);
    cout << "b1 value: " << b1.getValue() << endl;

    
    Box b2 = b1;
    b2.setValue(20);
    cout << "After changing b2:" << endl;
    cout << "b1 value: " << b1.getValue() << endl;
    cout << "b2 value: " << b2.getValue() << endl;

    
    Box b3;
    b3 = b1;
    b3.setValue(30);
    cout << "After changing b3:" << endl;
    cout << "b1 value: " << b1.getValue() << endl;
    cout << "b3 value: " << b3.getValue() << endl;

    return 0;
}
