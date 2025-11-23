#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* next;
    Node(int k) {
        key=k;
        next=NULL;
    }
};

class Hash {
public:
    Node* table[10];
    Hash() {
        for(int i=0;i<10;i++) table[i]=NULL;
    }
    int hashFunc(int k) {
        return k%10;
    }
    void insert(int k) {
        int index=hashFunc(k);
        Node* n=new Node(k);
        if(table[index]==NULL) table[index]=n;
        else {
            Node* t=table[index];
            while(t->next!=NULL) t=t->next;
            t->next=n;
        }
    }
    void removeKey(int k) {
        int index=hashFunc(k);
        Node* t=table[index];
        Node* p=NULL;
        while(t!=NULL) {
            if(t->key==k) {
                if(p==NULL) table[index]=t->next;
                else p->next=t->next;
                delete t;
                return;
            }
            p=t;
            t=t->next;
        }
    }
    void search(int k) {
        int index=hashFunc(k);
        Node* t=table[index];
        while(t!=NULL) {
            if(t->key==k) {
                cout<<"Found"<<endl;
                return;
            }
            t=t->next;
        }
        cout<<"Not found"<<endl;
    }
    void display() {
        for(int i=0;i<10;i++) {
            cout<<i<<": ";
            Node* t=table[i];
            while(t!=NULL) {
                cout<<t->key<<" ";
                t=t->next;
            }
            cout<<endl;
        }
    }
};

int main() {
    Hash h;
    h.insert(10);
    h.insert(20);
    h.insert(21);
    h.search(20);
    h.removeKey(21);
    h.display();
}
