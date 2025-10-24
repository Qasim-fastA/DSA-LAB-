#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) {
        name = n;
        score = s;
        next = NULL;
    }
};

void addNode(Node*& head, string n, int s) {
    Node* newNode = new Node(n, s);
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int getMax(Node* head) {
    int mx = 0;
    while (head) {
        if (head->score > mx) mx = head->score;
        head = head->next;
    }
    return mx;
}

void radixSort(Node*& head) {
    int maxVal = getMax(head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        Node* arr[10000]; int n = 0;
        Node* temp = head;
        while (temp) { arr[n++] = temp; temp = temp->next; }
        Node* output[10000]; int count[10] = {0};
        for (int i = 0; i < n; i++) count[(arr[i]->score / exp) % 10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            int idx = (arr[i]->score / exp) % 10;
            output[--count[idx]] = arr[i];
        }
        for (int i = 0; i < n - 1; i++) output[i]->next = output[i + 1];
        output[n - 1]->next = NULL;
        head = output[0];
    }
}

Node* mid(Node* start, Node* end) {
    if (!start) return NULL;
    Node* slow = start; Node* fast = start->next;
    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node* binSearch(Node* head, int key, string n) {
    Node* start = head; Node* end = NULL;
    do {
        Node* m = mid(start, end);
        if (!m) return NULL;
        if (m->score == key && m->name == n) return m;
        else if (m->score < key) start = m->next;
        else end = m;
    } while (end == NULL || end != start);
    return NULL;
}

void del(Node*& head, string n, int s) {
    Node* t = binSearch(head, s, n);
    if (!t) return;
    if (head == t) { head = head->next; delete t; return; }
    Node* temp = head;
    while (temp->next != t) temp = temp->next;
    temp->next = t->next;
    delete t;
}

void show(Node* h) {
    while (h) { cout << h->name << " " << h->score << endl; h = h->next; }
}

int main() {
    Node* head = NULL;
    addNode(head, "Ayan", 90);
    addNode(head, "Zameer", 60);
    addNode(head, "Sara", 70);
    addNode(head, "Sohail", 30);
    addNode(head, "Ahmed", 20);
    radixSort(head);
    show(head);
    string n; int s;
    cout << "Enter name: ";
    cin >> n;
    cout << "Enter score: ";
    cin >> s;
    del(head, n, s);
    show(head);
    return 0;
}
