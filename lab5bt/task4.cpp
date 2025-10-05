#include <iostream>
using namespace std;



struct Node {
    int data;
    Node* next= NULL;
};

class linkedlist{
   
public :

 Node* head ;  
 linkedlist() : head(nullptr) {}

    
    void insertAtEnd(int val ) {
        Node* newNode = new Node();
        newNode->data= val ;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }


    ~linkedlist() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

};

 bool searchll(Node* node, int target) {
        if (node == nullptr)
            return false;
        if (node->data == target)
            return true;
        bool found = searchll(node->next, target);
        return found;
    }


int main() {
    linkedlist list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    int val;
    cout << "Enter number to find: ";
    cin >> val;
    
    if (searchll(list.head,30))
        cout << val << " is in the list."<<endl;
    else
        cout << val << " is not in the list."<<endl;

    return 0;
}
