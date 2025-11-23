#include <iostream>
using namespace std;

class PairNode {
public:
    int a,b;
    PairNode* next;
    PairNode(int x,int y) {
        a=x;
        b=y;
        next=NULL;
    }
};

class HashPairs {
public:
    PairNode* table[1000];
    HashPairs() {
        for(int i=0;i<1000;i++) table[i]=NULL;
    }
    void insert(int sum,int a,int b) {
        PairNode* n = new PairNode(a,b);
        if(table[sum]==NULL) table[sum]=n;
        else {
            n->next = table[sum];
            table[sum]=n;
        }
    }
    bool exists(int sum,int &a1,int &b1,int &a2,int &b2) {
        if(table[sum]==NULL) return false;
        PairNode* first=table[sum];
        if(first->next==NULL) return false;
        a1=first->a;
        b1=first->b;
        a2=first->next->a;
        b2=first->next->b;
        return true;
    }
};

int main() {
    int arr[]={3,4,7,1,2,9,8};
    int n=7;
    HashPairs h;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int sum=arr[i]+arr[j];
            int a1,b1,a2,b2;
            if(h.exists(sum,a1,b1,a2,b2)) {
                cout<<"("<<a1<<","<<b1<<") and ("<<arr[i]<<","<<arr[j]<<")"<<endl;
                return 0;
            }
            h.insert(sum,arr[i],arr[j]);
        }
    }
    cout<<"No pairs found"<<endl;
}
