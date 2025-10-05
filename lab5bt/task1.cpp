#include<iostream>
using namespace std ;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class linkedlist{
   
public :

 Node* head ;  
 linkedlist() : head(nullptr) {}

    
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
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
 void printReverse(Node* node) {
         if (node == nullptr) return;
        printReverse(node->next);
        cout << node->data << " "<<endl;
        
    }
int main(){
    linkedlist obj ;
    obj.insertAtEnd(5);
    obj.insertAtEnd(4);
    obj.insertAtEnd(3);
    obj.insertAtEnd(2);
    obj.insertAtEnd(1);

    printReverse(obj.head);

}