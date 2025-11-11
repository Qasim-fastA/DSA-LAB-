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

int getBalance(Node* n) {
    if (!n) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
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
    else return root;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int b = getBalance(root);
    if (b > 1 && key < root->left->key)
        return rightRotate(root);
    if (b < -1 && key > root->right->key)
        return leftRotate(root);
    if (b > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (b < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int findMin(Node* root) {
    while (root->left) root = root->left;
    return root->key;
}

int findMax(Node* root) {
    while (root->right) root = root->right;
    return root->key;
}

int main() {
    Node* root = NULL;
    int vals[] = {10,5,15,3,7,12};
    for (int i = 0; i < 6; i++) root = insert(root, vals[i]);
    cout << "Smallest: " << findMin(root) << endl;
    cout << "Largest: " << findMax(root) << endl;
    cout << "Left height: " << getHeight(root->left) << endl;
    cout << "Right height: " << getHeight(root->right) << endl;
    return 0;
}
