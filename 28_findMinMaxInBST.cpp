// Write a program to find minimum and maximum element in a BST.
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node* right;
    Node(int val):data(val),left(nullptr), right(nullptr){}
};
Node* insert(Node* root, int val){
    if(root == nullptr){
        return  new Node(val);
    }
    if(val<root->data){
        root->left= insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}
int findMin(Node* root){
    if (root == nullptr) {
        cout << "The tree is empty." << endl;
        return -1;
    }
    while(root->left != nullptr){
        root = root->left;
    }
    return root->data;
}

int findMax(Node* root){
    if(root == nullptr){
        cout<<"The tree is empty.\n";
        return -1;
    }
    while(root->right != nullptr){
        root = root->right;
    }
    return root->data;
}
int main(int argc, char const *argv[])
{
    Node* root = nullptr;
    int n;
    cout << "Enter the number of elements to insert in the BST: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    int minVal = findMin(root);
    if (minVal != -1) {
        cout << "Minimum value in the BST: " << minVal << endl;
    }
    int maxVal = findMax(root);
    if (maxVal != -1) {
        cout << "Maximum value in the BST: " << maxVal << endl;
    }
    return 0;
}
