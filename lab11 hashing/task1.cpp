#include <iostream>
using namespace std;

class Node {
public:
    string key, value;
    Node* next;
    Node(string k, string v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable {
public:
    Node* table[10];
    HashTable() {
        for(int i=0;i<10;i++) table[i]=NULL;
    }
    int hashFunc(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++) sum += s[i];
        return sum % 10;
    }
    void insert(string k,string v) {
        int index = hashFunc(k);
        Node* n = new Node(k,v);
        if(table[index]==NULL) table[index]=n;
        else {
            Node* temp = table[index];
            while(temp->next!=NULL) temp=temp->next;
            temp->next=n;
        }
    }
    void display() {
        for(int i=0;i<10;i++) {
            cout << i << ": ";
            Node* t = table[i];
            while(t!=NULL) {
                cout << "("<<t->key<<","<<t->value<<") ";
                t=t->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable myhash;
    myhash.insert("A","aaaaa");
    myhash.insert("B","bbbbb");
    myhash.insert("C","ccccc");
    myhash.insert("A","zzzzz");
    myhash.display();
}
