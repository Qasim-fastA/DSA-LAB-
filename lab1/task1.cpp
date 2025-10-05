#include <iostream>
using namespace std;

class BankAccount {
    int balance;
public:
    BankAccount() {
        balance = 0;
    }
    BankAccount(int b) {
        balance = b;
    }
    BankAccount(const BankAccount &obj) {
        balance = obj.balance;
    }
    void deduct(int amt) {
        balance = balance - amt;
    }
    int getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account1;
    cout << "Balance of account1: " << account1.getBalance() << endl;

    BankAccount account2(1000);
    cout << "Balance of account2: " << account2.getBalance() << endl;

    BankAccount account3(account2);
    account3.deduct(200);
    cout << "Balance of account3: " << account3.getBalance() << endl;
    cout << "Balance of account2: " << account2.getBalance() << endl;

    return 0;
}
