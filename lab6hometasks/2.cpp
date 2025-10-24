#include <iostream>
#include <string>
using namespace std;

struct Node {
    string site;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = NULL; }
    void push(string val) {
        Node* n = new Node;
        n->site = val;
        n->next = top;
        top = n;
    }
    string pop() {
        if (!top) return "";
        string x = top->site;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }
    void addFront(string val) {
        Node* n = new Node;
        n->site = val;
        n->next = head;
        head = n;
    }
    void removeFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void show() {
        Node* t = head;
        while (t) { cout << t->site << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    Stack s;
    string sites[5] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (int i = 0; i < 5; i++) {
        l.addFront(sites[i]);
        s.push(sites[i]);
    }
    s.pop(); l.removeFront();
    s.pop(); l.removeFront();
    l.show();
    return 0;
}
