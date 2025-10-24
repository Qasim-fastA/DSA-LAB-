#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

void add(Node*& head, int d) {
    Node* n = new Node(d);
    if (!head) head = n;
    else { Node* t = head; while (t->next) t = t->next; t->next = n; }
}

void swap(Node* a, Node* b) {
    int t = a->data;
    a->data = b->data;
    b->data = t;
}

Node* partition(Node* l, Node* h) {
    int x = h->data;
    Node* i = l;
    Node* j = l;
    while (j != h) {
        if (j->data < x) {
            swap(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swap(i, h);
    return i;
}

void quickSort(Node* l, Node* h) {
    if (h && l != h && l != h->next) {
        Node* p = partition(l, h);
        quickSort(l, p);
        quickSort(p->next, h);
    }
}

Node* last(Node* h) {
    while (h && h->next) h = h->next;
    return h;
}

void show(Node* h) {
    while (h) { cout << h->data << " "; h = h->next; }
}

int main() {
    int a[] = {10, 7, 8, 9, 1, 5, 3};
    Node* head = NULL;
    for (int i = 0; i < 7; i++) add(head, a[i]);
    quickSort(head, last(head));
    show(head);
    return 0;
}
