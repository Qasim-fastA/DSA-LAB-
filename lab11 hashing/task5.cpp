#include <iostream>
using namespace std;

class StudentHashTable {
public:
    string name[15];
    int roll[15];
    StudentHashTable() {
        for(int i=0;i<15;i++) {
            roll[i]=-1;
            name[i]="";
        }
    }
    void InsertRecord(int r,string n) {
        int index=r%15;
        int attempt=0;
        while(attempt<15) {
            int idx=(index + attempt*attempt)%15;
            if(roll[idx]==-1) {
                roll[idx]=r;
                name[idx]=n;
                return;
            }
            attempt++;
        }
    }
    void SearchRecord(int r) {
        int index=r%15;
        int attempt=0;
        while(attempt<15) {
            int idx=(index + attempt*attempt)%15;
            if(roll[idx]==r) {
                cout<<name[idx]<<endl;
                return;
            }
            attempt++;
        }
        cout<<"Record not found"<<endl;
    }
};

int main() {
    StudentHashTable s;
    s.InsertRecord(10,"Ali");
    s.InsertRecord(25,"Sara");
    s.SearchRecord(25);
}
