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

    void rearrangeAltReverse() {
        if (!head || !head->next) return;

        
        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;

        while (odd->next && even->next) {
            odd->next = even->next;
            odd = odd->next;

            if (odd->next) {
                even->next = odd->next;
                even = even->next;
            } else {
                even->next = NULL;
                break;
            }
        }
        even->next = NULL;

        
        Node* prev = NULL;
        Node* curr = evenHead;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        Node* reversedEven = prev;

        
        odd->next = reversedEven;
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
    list.insertAtEnd(10);
    list.insertAtEnd(4);
    list.insertAtEnd(9);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(5);
    list.insertAtEnd(9);
    list.insertAtEnd(2);
    list.insertAtEnd(4);

    cout << "Original List: ";
    list.display();

    list.rearrangeAltReverse();

    cout << "Modified List: ";
    list.display();

    return 0;
}




















