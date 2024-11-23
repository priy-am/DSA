// Write a program to delete an element in a circular singly linked list
// a. at front
// b. at the end of the list
// c. at any specific position

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){}
};
class LinkedList{
private:
    Node* head;
public:
    LinkedList():head(nullptr){}
    //append
    void append(int data){
        Node* newNode = new Node(data);
        if(!head){
            head = newNode;
            head->next = head;
            return;
        }
        Node* ptr = head;
        while (ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = head;
        
    }
    void dltAtFront(){
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head ;
        Node* last = head ;
        while(last->next != head){
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete temp;
    }
    void dltAtEnd(){
        Node*ptr = head;
        if(!head){
            cout<<"List is empty\n";
            return;
        }
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        while(ptr->next->next != head){
            ptr = ptr->next;
        }
        Node* temp = ptr->next;
        ptr->next = head;
        delete temp;
    }
    void dltPos(int pos){
        Node* ptr = head;
        if(pos == 1){
            dltAtFront();
            return;
        }
        for(int i = 1; i<pos-1; i++){
            ptr = ptr->next;
        }
        if(ptr->next == head){
            dltAtEnd();
            return;
        }
        Node* ptr1 = ptr->next;
        ptr->next = ptr1->next;
        delete ptr1;

    }
    void display(){
        if(!head){
            cout<<"List is empty\n";
            return;
        }
        Node* ptr = head;
        do{
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        } while (ptr != head);
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
        list.append(data);
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
            list.dltAtFront();
            list.display();
            break;
        }
        case 2 :{
            list.dltAtEnd();
            list.display();
            break;
        }
        case 3 :{
            int pos;
            cout<<"Enter the position where you want to delete :- ";
            cin>>pos;
            list.dltPos( pos);
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

