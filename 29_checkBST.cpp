// Write a program to check if a tree is BST.
#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); 
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val); 
    }
    return root;
}

bool isBSTUtil(Node* root, int min, int max) {
    if (root == nullptr) {
        return true; 
    }
    if (root->data <= min || root->data >= max) {
        return false;
    }
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
int main() {
    Node* root = nullptr;
    int n;
    cout << "Enter the number of elements to insert in the tree: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    if (isBST(root)) {
        cout << "The tree is a BST." << endl;
    } else {
        cout << "The tree is NOT a BST." << endl;
    }
    return 0;
}