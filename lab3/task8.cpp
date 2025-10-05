#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) : data(d), next(NULL), prev(NULL) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->data;
            if (t->next) cout << " <-> ";
            t = t->next;
        }
        cout << endl;
    }
};


void concatenate(DoublyLinkedList &L, DoublyLinkedList &M) {
    if (!L.head) { 
        L.head = M.head;
        L.tail = M.tail;
        return;
    }
    if (!M.head) return; 

    L.tail->next = M.head;
    M.head->prev = L.tail;
    L.tail = M.tail;
}

int main() {
    DoublyLinkedList L, M;

    L.insertAtEnd(1);
    L.insertAtEnd(2);
    L.insertAtEnd(3);

    M.insertAtEnd(4);
    M.insertAtEnd(5);
    M.insertAtEnd(6);

    cout << "List L: ";
    L.display();
    cout << "List M: ";
    M.display();

    concatenate(L, M);

    cout << "After Concatenation: ";
    L.display();
}
