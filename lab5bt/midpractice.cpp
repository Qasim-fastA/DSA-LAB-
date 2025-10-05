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

int findlength(Node* node){
   static int length = 0;
    if(node == nullptr ){
    return length ;
   }
   
   length++;
   findlength(node->next);    

}  

bool searchValue(int val,Node* node ){
     if(node==nullptr){
        return false ;
     }
    
    if(node->data==val){
    return true ; 
  }

  bool found =searchValue(val , node->next);
  return found ;

}

int main(){
    linkedlist obj ;
    obj.insertAtEnd(5);
    obj.insertAtEnd(4);
    obj.insertAtEnd(3);
    obj.insertAtEnd(2);
    obj.insertAtEnd(1);

    int n = findlength(obj.head);
    cout<<"length is "<<n;
}