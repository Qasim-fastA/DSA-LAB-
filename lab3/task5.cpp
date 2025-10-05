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

    LinkedList getReversedCopy() {
        LinkedList revList;
        Node* curr = head;
        while (curr) {
            revList.insertAtHead(curr->data);  
            curr = curr->next;
        }
        return revList;
    }
    
    bool isPalindrome(){
        LinkedList revList = getReversedCopy();
        Node* orig = head;
        Node* rev = revList.head;

        while (orig && rev) {
            if (orig->data != rev->data) return false;
            orig = orig->next;
            rev = rev->next;
        }
        return true;
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
    LinkedList list1;
    list1.insertAtEnd('1');
    list1.insertAtEnd('0');
    list1.insertAtEnd('2');
    list1.insertAtEnd('0');
    list1.insertAtEnd('1');

    list1.display();
    if (list1.isPalindrome())
        cout << "Linked List is a Palindrome\n";
    else
        cout << "Linked List is NOT a Palindrome\n";

    LinkedList list2;
    string s = "BORROWORROB";
    for (int i = 0; i < s.size(); i++) list2.insertAtEnd(s[i]);

    list2.display();
    if (list2.isPalindrome())
        cout << "Linked List is a Palindrome\n";
    else
        cout << "Linked List is NOT a Palindrome\n";

    return 0;
}
