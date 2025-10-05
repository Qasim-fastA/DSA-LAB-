#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() : head(NULL) {}

    
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head; 
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode; 
    }

    
    void insertAtPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid position\n";
            return;
        }
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }
        if (count < pos - 1) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    
    void deleteNode(int val) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        
        if (head->data == val) {
            if (head->next == head) { 
                delete head;
                head = NULL;
                return;
            }
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            Node* toDelete = head;
            temp->next = head->next;
            head = head->next;
            delete toDelete;
            return;
        }

        
        Node* curr = head->next;
        Node* prev = head;
        while (curr != head) {
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Value " << val << " not found\n";
    }

    
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.display();

    cll.insertAtBeginning(5);
    cll.display();

    cll.insertAtPosition(15, 3);
    cll.display();

    cll.deleteNode(20);
    cll.display();

    cll.deleteNode(100); 
    cll.display();

    return 0;
}
