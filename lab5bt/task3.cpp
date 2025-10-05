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

void FindLength(Node* node ){
    static int size ;
    Node* temp = new Node();
    temp = node ;
    if(temp  == nullptr){
      cout<<"length= "<<size;
      return ;
    } 
    size++ ;
    FindLength(temp->next);

}


int main(){
    linkedlist obj ;
    
    obj.insertAtEnd(5);
    obj.insertAtEnd(6);
    obj.insertAtEnd(3);
    obj.insertAtEnd(7);
    obj.insertAtEnd(8);
    obj.insertAtEnd(10);

    FindLength(obj.head);

    return 0 ;
}