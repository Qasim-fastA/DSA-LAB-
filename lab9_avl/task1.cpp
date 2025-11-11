#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k) {
        key = k;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node* n) {
    if (!n) return 0;
    return n->height;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    if (root->key == 10)
        return leftRotate(root);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int a[] = {10,20,30,40,50};
    for (int i = 0; i < 5; i++) root = insert(root, a[i]);
    root = insert(root, 15);
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Height: " << getHeight(root) << endl;
    return 0;
}
