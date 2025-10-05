#include<iostream>
using namespace std ;

struct Node{
    int data ;
    Node* next ;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(0);
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
    
    void insertAtHead(char d) {
        Node* newNode = new Node(d);
        newNode->next = head;
        head = newNode;
    }

        void deleteValue(char val) {
        if (!head) {
            cout << "List is empty";
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted value " ;
            return;
        }

        Node* prev = head;
        Node* curr = head->next;
        while (curr) {
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                cout << "Deleted value " << val ;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        
        cout << "Value not found ";
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
    list.insertAtEnd('A');
    list.insertAtEnd('B');
    list.insertAtEnd('C');
    list.insertAtEnd('D');
    list.insertAtEnd('E');

    cout << "Original List: ";
    list.display();

    list.deleteValue('C'); 
    list.display();

    list.deleteValue('A');  
    list.display();

    list.deleteValue('Z');  
    list.display();

    return 0;
}