#include <iostream>
#include <string>
using namespace std;

class Exam {
    string *name;
    string *date;
    int *score;
public:
    Exam() {
        name = new string(" ");
        date = new string(" ");
        score = new int(0);
    }
    void setDetails(string n, string d, int s) {
        *name = n;
        *date = d;
        *score = s;
    }
    void display() {
        cout << "Name: " << *name << endl;
        cout << "Date: " << *date << endl;
        cout << "Score: " << *score << endl;
    }
    ~Exam() {
        delete name;
        delete date;
        delete score;
    }
};

int main() {
    Exam exam1;
    exam1.setDetails("Ali", "22-08-2025", 90);
    cout << "Exam1 details:" << endl;
    exam1.display();

    Exam exam2 = exam1;
    cout << "\nExam2 details (after shallow copy):" << endl;
    exam2.display();

    return 0;
}
