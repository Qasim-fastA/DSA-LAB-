#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void rotate(int k) {
        if (head == NULL || k == 0) return;

        Node* temp = head;
        int count = 1;
        while (count < k && temp != NULL) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) return;

        Node* kthNode = temp;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = head;
        head = kthNode->next;
        kthNode->next = NULL;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, value, k;

    cout << "Enter number of elements in the list: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertEnd(value);
    }

    cout << "Enter the number of elements to rotate: ";
    cin >> k;

    cout << "Original list: ";
    list.display();

    list.rotate(k);

    cout << "After rotation: ";
    list.display();

    return 0;
}
