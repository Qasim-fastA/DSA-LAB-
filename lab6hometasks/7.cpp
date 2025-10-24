#include <iostream>
#include <string>
using namespace std;

class Queue {
    string patrons[10];
    int front, rear;
public:
    Queue() { front = rear = -1; }
    void enqueue(string name) {
        if (rear == 9) return;
        if (front == -1) front = 0;
        patrons[++rear] = name;
    }
    void dequeue() {
        if (front == -1 || front > rear) return;
        front++;
    }
    void show() {
        for (int i = front; i <= rear; i++) cout << patrons[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int ch;
    string name;
    do {
        cout << "1 Add\n2 Remove\n3 Show\n0 Exit\n";
        cin >> ch;
        if (ch == 1) { cin >> name; q.enqueue(name); }
        else if (ch == 2) q.dequeue();
        else if (ch == 3) q.show();
    } while (ch != 0);
    return 0;
}
