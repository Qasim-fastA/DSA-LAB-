#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Stack {
public:
    Node* top;
    Stack() { top = NULL; }
    void push(string val) {
        Node* n = new Node;
        n->data = val;
        n->next = top;
        top = n;
    }
    string pop() {
        if (!top) return "";
        string x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }
    void show() {
        Node* t = top;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push("x");
    s.push("=");
    s.push("12");
    s.push("+");
    s.push("13");
    s.push("-");
    s.push("5");
    s.push("*");
    s.push("(0.5+0.5)");
    s.push("+");
    s.push("1");
    s.push("20");
    s.show();
    return 0;
}
