// Write a program to insert an element in a given BST.
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};
Node* insert(Node* root, int val){
    if(root == nullptr){
        return new Node(val);
    }
    if(val< root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

void inOrder(Node* root){
    if(root == nullptr) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
};

int main(int argc, char const *argv[])
{
    Node* root = nullptr;
    int n;
    cout << "Enter the number of elements to insert in the BST: ";
    cin >> n;
    for(int i= 0; i<n;i++){
        int val;
        cin>>val;
        root = insert(root, val);
    }
    cout << "\nIn-order Traversal after insertion: ";
    inOrder(root);
    return 0;
}

