#include <iostream>
using namespace std;

class Queue {
    int arr[10];
    int front, rear;
public:
    Queue() { front = rear = -1; }
    void enqueue(int x) {
        if (rear == 9) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() {
        if (front == -1 || front > rear) return;
        front++;
    }
    void show() {
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int ids[7] = {13, 7, 4, 1, 6, 8, 10};
    for (int i = 0; i < 7; i++) q.enqueue(ids[i]);
    q.show();
    q.dequeue();
    q.dequeue();
    q.show();
    return 0;
}
