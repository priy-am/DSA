// Write a program to traverse a given Binary Search Tree(BST).
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

Node* insert(Node* root, int val){
    if(root == nullptr){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }else if(val >= root->data){
        root->right = insert(root->right, val);
    }
    return root;
};
void inOrder(Node* root){
//inorder Tl-R-Tr
    if(root == nullptr) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(Node*root){
    // Root -> Left -> Right
    if (root == nullptr) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
};
void postOrder(Node* root){
    // Left -> Right -> Root
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<< " ";
}

int main(int argc, char const *argv[])
{
    Node* root = nullptr;

    int n;
    cout << "Enter the number of elements to insert in the BST: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    // Display traversals
    cout << "\nIn-order Traversal: ";
    inOrder(root);

    cout << "\nPre-order Traversal: ";
    preOrder(root);

    cout << "\nPost-order Traversal: ";
    postOrder(root);
    return 0;
}
