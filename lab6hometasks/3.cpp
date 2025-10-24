#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = NULL; }
    void push(char val) {
        Node* n = new Node;
        n->data = val;
        n->next = top;
        top = n;
    }
    char pop() {
        if (!top) return 0;
        char x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }
    char peek() { return top ? top->data : 0; }
    bool isEmpty() { return top == NULL; }
};

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i", postfix = "";
    Stack s;
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) postfix += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') postfix += s.pop();
            s.pop();
        } else {
            while (!s.isEmpty() && prec(c) <= prec(s.peek())) postfix += s.pop();
            s.push(c);
        }
    }
    while (!s.isEmpty()) postfix += s.pop();
    cout << postfix;
    return 0;
}
