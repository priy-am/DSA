/*
Q7. Write a program to insert an element in a singly linked list
a. at front
b. at the end of the list
c. at any specific position
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    //constructor of node
    Node(int val): data(val), next(nullptr){}
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList():head(nullptr){}     //constructor ;- use for initialize the val

    //insert in the front
    void insertAtFront(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    //insert at end
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    //insert at any specific postion 
    void insertAtSpecificPosition(int val, int pos){
        Node* newnode = new Node(val);
        Node* ptr;
        if(pos == 1){
            newnode->next = head;
            head = newnode;
            return;
        }
        ptr = head;
        for(int i = 1; i< pos-1; i++){
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }

    //display
    void display()const{
        Node* ptr;
        ptr = head;
        while(ptr != nullptr){
            cout<<ptr->data<< " -> ";
            ptr = ptr->next;
        }
        cout<<"Null"<<endl;
    }

    //deconstructor :- use for delete the linked list which take space
    ~LinkedList(){
        Node* temp;
        while( head != nullptr ){
            temp = head;
            head = head->next;
            delete temp;
        }
    };
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
        if(i == 0){
            list.insertAtFront(data);
        }else{
        list.insertAtEnd(data);
        }
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
            list.insertAtSpecificPosition(val, pos);
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
