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
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void rotate(int n) {
        if (n == 0 || head == nullptr) return;

        Node* temp = head;
        int length = 1;
        while (temp->next != nullptr) {
            temp = temp->next;
            length++;
        }

        n = n % length;
        if (n == 0) return;

        temp->next = head;

        Node* newTail = head;
        for (int i = 1; i < n; i++) {
            newTail = newTail->next;
        }

        head = newTail->next;
        newTail->next = nullptr;
    }
};

int main() {
    singlyLL list;
    int arr[] = {5, 3, 1, 8, 6, 4, 2};
    for (int val : arr) {
        list.insertATtail(val);
    }

    cout << "Given list: ";
    list.display();

    cout << "Enter the number: ";
    int n;
    cin >> n;

    list.rotate(n);

    cout << "After rotation: ";
    list.display();

    return 0;
}
