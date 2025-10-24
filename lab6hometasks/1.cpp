#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = NULL; }
    void push(string val) {
        Node* n = new Node;
        n->data = val;
        n->next = top;
        top = n;
    }
    bool isEmpty() { return top == NULL; }
    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void showTop() {
        if (!isEmpty()) cout << top->data << endl;
    }
};

int main() {
    Stack s;
    s.push("Task1");
    s.push("Task2");
    s.push("Task3");
    cout << s.isEmpty() << endl;
    s.showTop();
    s.pop();
    s.showTop();
    return 0;
}
