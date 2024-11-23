// Write a program to search an element in a BST.	
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val), left(nullptr), right(nullptr){}
};
Node* insert(Node* root, int val){
    if(root == nullptr){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert(root->left, val);
    }else if(val >= root->data){
        root->right = insert(root->right, val);
    }
    return root;
}
bool searching(Node* root, int key){
    if(root == nullptr) return false ;
    if(root->data == key) return true;
    if(root->data > key){
        return searching(root->left, key);
    }
    return searching(root->right , key);
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
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    if(searching){
        cout<<"Element " << key << " is present in the BST.\n";
    }else{
        cout<<"Element "<< key<< " is not present\n";
    }
    return 0;
}
