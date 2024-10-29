// Write a program to remove duplicates from the sorted linked list
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {} // constructor
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {} // constructor

    //insert the element
    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* ptr = head;
        while(ptr->next!= nullptr){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    //remove duplicate 

    //display
    void display(){
        Node* ptr = head;
        while(ptr!=nullptr){
            cout<<ptr->data;
            ptr = ptr->next;
        }
        cout<<"Null";
    }

    // deconstructor
    ~LinkedList(){
        Node *temp;
        while (head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
