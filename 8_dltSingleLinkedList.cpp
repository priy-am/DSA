/*
Q8. Write a program to delete an element in a singly linked list
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

    Node(int val):data(val),next(nullptr){}   //constructor
};


class LinkedList
{
private:
    Node* head;
public:
    LinkedList():head(nullptr){}   //constructor

    //for insert the elemnt 
    void insertAtFront(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            newNode = head;
            return;
        }
        Node*ptr = head;
        while(ptr->next != nullptr){
            ptr= ptr->next;
        }
        ptr->next = newNode;
        
    }

//delete from the front
    void deleteAtFront(){
        if(head == nullptr){
            cout<<"List is empty\n";
            return;
        }
        Node*temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd(){ 
        if(head == nullptr){
            cout<<"List is empty\n";
            return;
        }
        if(head->next == nullptr){
            delete head;
            head == nullptr;
            return;
        }

        Node*ptr = head;
        while(ptr->next->next != nullptr){
            ptr= ptr->next;
        }
        delete ptr->next;
        ptr->next = nullptr;
    }

    void deleteAtSpecificPosition(int pos){
        if(head == nullptr){
            cout<<"List is empty\n";
            return;
        }
        Node *ptr = head;
        for(int i = 1; i< pos-1; i++){
            ptr = ptr->next;
        }
        // 7 8 9 
        Node* dltnode = ptr->next;
        ptr->next = dltnode->next;
        delete dltnode;

    }

//display
    void display() const{
        Node* ptr = head;
        while(ptr != nullptr){
            cout<<ptr->data<<" -> ";
            ptr = ptr->next;
        }
    cout<<"NUll\n";
    }
    //deconstructor
    ~LinkedList(){
        Node* temp;
        while(temp != nullptr){
            temp = head;
            head = temp->next;
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
        cout<<"Enter the 1. for delete the element at the front\n 2. for delete the element at the End.\n 3. for the delete the element at the specific postion:- ";
        cin>>value;
        switch (value)
        {
        case 1 :{
            list.deleteAtFront();
            list.display();
            break;
        }
        case 2 :{
            list.deleteAtEnd();
            list.display();
            break;
        }
        case 3 :{
            int pos;
            cout<<"Enter the position where you want to delete :- ";
            cin>>pos;
            list.deleteAtSpecificPosition( pos);
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
