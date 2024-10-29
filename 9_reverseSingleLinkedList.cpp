// Q9. Write a program to reverse a singly linked list
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val):data(val),next(nullptr){}  //constructor
};

class LinkedList 
{
private: 
    Node* head;
public:
    LinkedList():head(nullptr){}    //constructor

    //insert at the end for the making linked list
    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    //reverse 
    void reverse(){
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while(current != nullptr){
            //8 3 4 6 9 5
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    //display
    void display(){
        Node* ptr = head;
        while(ptr!=nullptr){
            cout<<ptr->data<<" -> ";
            ptr = ptr->next;
        }
        cout<<"Null";
    }

//deconstructor
    ~LinkedList(){
        Node* temp ;
        while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
        } 
    }
};


int main(int argc, char const *argv[])
{
    int data, size;
    LinkedList list;
    cout<<"Enter the number of element in linkedList:- ";
    cin>>size;
    cout<<"Enter the data of the LinkedList element:- ";
    for(int i=1; i<=size; i++){
        cin>>data;
        list.insertAtEnd(data);
    }
    cout<<"Display linkedList are :- \n";
    list.display();
    cout<<endl;

    cout<<"Reverse LinkedList are:- \n";
    list.reverse();
    list.display();
    return 0;
}
