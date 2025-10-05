#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

   
    void addLast(int value) {
        Node* n = new Node(value);
        if (head == NULL) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    
    void show() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* t = head;
        while (t != NULL) {
            cout << t->data;
            if (t->next != NULL) cout << " -> ";
            t = t->next;
        }
        cout << " -> NULL" << endl;
    }
};


void separateEvenOdd(List* lst) {
    if (lst->head == NULL || lst->head->next == NULL) {
        cout << "List too small to rearrange" << endl;
        return;
    }

    List* evens = new List();
    List* odds = new List();

    Node* cur = lst->head;
    while (cur != NULL) {
        if (cur->data % 2 == 0)
            evens->addLast(cur->data);
        else
            odds->addLast(cur->data);
        cur = cur->next;
    }

    if (evens->head != NULL) {
        evens->tail->next = odds->head;
        lst->head = evens->head;
        if (odds->tail != NULL) lst->tail = odds->tail;
        else lst->tail = evens->tail;
    } else { 
        lst->head = odds->head;
        lst->tail = odds->tail;
    }

    delete evens;
    delete odds;
}

int main() {
    List* lst = new List();
    lst->addLast(5);
    lst->addLast(6);
    lst->addLast(3);
    lst->addLast(2);
    lst->addLast(1);
    lst->addLast(8);
    lst->addLast(4);

    cout << "Original: ";
    lst->show();

    separateEvenOdd(lst);

    cout << "Rearranged (Even first): ";
    lst->show();
}
