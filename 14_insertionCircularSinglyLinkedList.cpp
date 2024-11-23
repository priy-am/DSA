// Q14. Write a program to insert an element in a circular singly linked list
// a. at front
// b. at the end of the list
// c. at any specific position

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node*next;
    Node(int val):data(val),next(nullptr){}
};
class LinkedList
{
private:
    Node*head;
public:
    LinkedList():head(nullptr){}

//insert at front 
    void insertAtFront(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            head->next = head;
            return;
        }
        Node* ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        newNode->next = head;
        ptr->next = newNode;
        head = newNode;
    }

//insert at end
    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            head->next = head;
            return;
        }
        Node* ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = head;
    }

    // insert at specific pos 
    void insertAtPos(int data , int pos){
        Node* newNode = new Node(data);
        if(pos == 1){
            insertAtFront(data);
            return;
        }
        Node* ptr = head;
        for(int i = 1; i<pos-1; i++){
            ptr  = ptr->next;
        }
        if(ptr->next->next == head){
            insertAtEnd(data);
            return;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    //display
    void display(){
        Node* ptr = head;
        do{
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }while( ptr != head);
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
    LinkedList list;
    char want;
    int len, data;
    cout<<"Enter the number of list that you want to make:- ";
    cin>>len;
    cout<<"Enter the data of the list one by one:- ";
    for(int i = 0; i<len; i++){
        cin>>data;
        list.insertAtEnd(data);
    }
    cout<<"The list element are \n";
    list.display();
    do
    {
        int value;
        cout<<"Enter the 1. for insert the element at the front\n 2. for insert the element at the End.\n 3. for the insert the element at the specific postion:- ";
        cin>>value;
        switch (value)
        {
        case 1 :{
            int val;
            cout<<"Enter the data of linked list that you want to insert:- ";
            cin>>val;
            list.insertAtFront(val);
            list.display();
            break;
        }
        case 2 :{
            int val;
            cout<<"Enter the data of linked list that you want o insert :- ";
            cin>>val;
            list.insertAtEnd(val);
            list.display();
            break;
        }
        case 3 :{
            int val, pos;
            cout<<"Enter the position where you want to insert and enter the data of that:- ";
            cin>>pos >>val;
            list.insertAtPos(val, pos);
            list.display();
            break;
        }
        
        default: cout<<"Invalid input\n";
            break;
        }

        cout<<"Do you want to try agin:- y for yes , n for no:- ";
        cin>>want;

    } while (want == 'y'||want == 'Y');
    
    return 0;
}

