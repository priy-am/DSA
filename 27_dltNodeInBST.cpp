/*	Write a program to delete an element from a given BST. Consider all the following cases:
(i) Leaf node deletion
(ii) Internal node deletion having one children
(iii) Internal node deletion with 2 children.	
*/
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int val):data(val),left(nullptr), right(nullptr){}
};
Node* insert(Node* root, int val){
    if(root == nullptr){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
};
void inOrder(Node* root){
    if(root== nullptr) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
Node* minValNode(Node* root){
    Node* current = root;
    while(current && current->left != nullptr){
        current = current->left;
    }
    return current;
}
Node* dltNode(Node* root, int key){
    if(root== nullptr){
        return root;
    }
    if(key<root->data){
        root->left = dltNode(root->left, key);
    }else if(key> root->data){
        root->right = dltNode(root->right, key);
    }else {
        //equal to root 
        if(root->left == nullptr && root->right== nullptr){
            //leaf Node
            delete root;
            return nullptr;
        }else if(root->left == nullptr){
            //internal node of one chile
            Node* temp = root->right;
            delete root;
            return temp; 
        }else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //internal node
        Node* temp = minValNode(root->right); //replace with successor 
        root->data = temp->data; 
        root->right = dltNode(root->right, temp->data); //for dlt that value which we replace with    
    }
    return root;
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
    cout << "\nIn-order Traversal before deletion: ";
    inOrder(root);
    int key;
    cout << "\nEnter the element to delete: ";
    cin >> key;
    root = dltNode(root, key);
    cout << "\nIn-order Traversal after deletion: ";
    inOrder(root);
    return 0;
}
