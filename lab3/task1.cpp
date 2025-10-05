#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class singlyLL {
public:
    Node* head;

    singlyLL() {
        head = nullptr;
    }

    void insertATtail(int val) {
        Node* n = new Node(val);

        if (head == nullptr) {
            head = n;
            cout << "inserted at tail (was empty)" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
        cout << "inserted at tail" << endl;
    }

    void insertAThead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        cout << "inserted at head" << endl;
    }

    void insertAfter(int pos, int val) {
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* n = new Node(val);
        Node* curr = head;

        for (int i = 0; i < pos; i++) {
            if (curr == nullptr) {
                cout << "Position out of bounds" << endl;
                delete n;
                return;
            }
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Position out of bounds" << endl;
            delete n;
            return;
        }

        n->next = curr->next;
        curr->next = n;
        cout << "inserted at position " << pos + 1 << endl;
    }

    void deleteAfter(int pos) {
        if (pos < 0 || head == nullptr) {
            cout << "Invalid position or empty list" << endl;
            return;
        }

        Node* curr = head;

        for (int i = 0; i < pos; i++) {
            if (curr == nullptr) {
                cout << "Position out of bounds" << endl;
                return;
            }
            curr = curr->next;
        }

        if (curr == nullptr || curr->next == nullptr) {
            cout << "No node to delete after position " << pos << endl;
            return;
        }

        Node* nodeToDelete = curr->next;
        curr->next = nodeToDelete->next;
        delete nodeToDelete;

        cout << "Deleted node after position " << pos << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {3, 1, 2, 5, 8};
    singlyLL n;

    cout << "Displaying array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        n.insertAThead(arr[i]);
    }

    n.insertATtail(9);
    n.insertAfter(3, 11);
    n.insertAThead(4);
    n.deleteAfter(1);
    n.deleteAfter(2);
    n.deleteAfter(5); 

    cout << "Linked list contents: ";
    n.display();

    return 0;
}
