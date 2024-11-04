// Q13. Write a program to delete an element in a doubly linked list
// a. at front
// b. at the end of the list
// c. at any specific position
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data):data(data),prev(nullptr),next(nullptr){}
};

class LinkedList 
{
private:
    Node* head;
public:
    LinkedList():head(nullptr){}
    // insertion
    void append (int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* ptr = head;
        while(ptr->next !=nullptr){
            ptr  = ptr->next;
        }
        newNode->prev = ptr;
        ptr->next = newNode;
    }

    //deletion at front
    void dltAtFront(){
        if(head == nullptr){
            cout<<"List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
         if (head != nullptr) {  // Added check to avoid dereferencing nullptr
            head->prev = nullptr;
        }
        delete temp;
    }

//deletion at end
    void dltAtEnd(){
         if (head == nullptr) {  // Added check for empty list
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {  // Added check for single node list
            delete head;
            head = nullptr;
            return;
        }
        Node* ptr = head;
        while(ptr->next->next!=nullptr){
            ptr= ptr->next;
        }
        Node* temp = ptr->next;
        ptr->next = nullptr;
        delete temp;

    }

    // delete at specific pos
    void dltPos(int pos){
        if (head == nullptr) {
            cout << "List is empty, no nodes to delete.\n";
            return;
        }


        if(pos == 1){
            dltAtFront();
            return;
        }
        Node* ptr = head;
        for(int i = 1; i<pos-1;i++){
            ptr = ptr->next;
        }
        if(ptr->next->next == nullptr){
            dltAtEnd();
            return;
        }
        Node* temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        delete(temp);
    }

    //display
    void display(){
        Node* ptr= head;
        while(ptr!=nullptr){
            cout<<ptr->data<<" ";
            ptr= ptr->next;
        }
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
