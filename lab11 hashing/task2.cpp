#include <iostream>
using namespace std;

class Node {
public:
    string word, meaning;
    Node* next;
    Node(string w,string m) {
        word=w;
        meaning=m;
        next=NULL;
    }
};

class Dictionary {
public:
    Node* table[100];
    Dictionary() {
        for(int i=0;i<100;i++) table[i]=NULL;
    }
    int hashKey(string w) {
        int sum=0;
        for(int i=0;i<w.length();i++) sum+=w[i];
        return sum % 100;
    }
    void Add_Record(string w,string m) {
        int index = hashKey(w);
        Node* n=new Node(w,m);
        if(table[index]==NULL) table[index]=n;
        else {
            Node* t=table[index];
            while(t->next!=NULL) t=t->next;
            t->next=n;
        }
    }
    void Word_Search(string w) {
        int index=hashKey(w);
        Node* t=table[index];
        while(t!=NULL) {
            if(t->word==w) {
                cout<<t->meaning<<endl;
                return;
            }
            t=t->next;
        }
        cout<<"Not found"<<endl;
    }
    void Print_Dictionary() {
        for(int i=0;i<100;i++) {
            if(table[i]!=NULL) {
                cout<<"index "<<i<<": ";
                Node* t=table[i];
                while(t!=NULL) {
                    cout<<"("<<t->word<<", "<<t->meaning<<") ";
                    t=t->next;
                }
                cout<<endl;
            }
        }
    }
};

int main() {
    Dictionary d;
    d.Add_Record("AB","FASTNU");
    d.Add_Record("CD","CS");
    d.Word_Search("AB");
    d.Print_Dictionary();
}
