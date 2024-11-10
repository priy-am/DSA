// Write a program to implement stack using linked list (Show all the operations like insertion, deletion and display)

#include <iostream>
using namespace std;

struct  Node
{
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){}
};

class StackByLinkedList
{
private:
    Node* top;
public:
    StackByLinkedList():top(nullptr){}
    bool isEmpty(){
        return top == nullptr;
    }

    void display(){
        Node* current = top;
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<"Stack element:- \n";
        while(current != nullptr){
            cout<<current->data<<", ";
            current = current->next;
        }
        cout<<endl;

    }

    void pop(){
        if(isEmpty()){
            cout << "Stack underflow! Cannot pop." << endl;
            return;
        }
        Node* current = top;
        cout << "Popped " << top->data << " from stack." << endl;
        top = top->next;
        free(current);
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(isEmpty()){
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

};

int main(int argc, char const *argv[])
{
    StackByLinkedList stack;
    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;
    int data;
    cout<<"Enter the data of the stack:- ";
    for(int i = 0 ; i<stackSize; i++){
        cin>>data;
        stack.push(data);
    }
    stack.display();
    char want;
    do{
        int choice;
        cout<<"Enter 1. for push \n 2. for pop\n 3. display:- ";
        cin>>choice;
        switch (choice)
        {
        case 1: 
            int val;
            cout<<"Enter the value that you want to insert:- ";
            cin>>val;
            stack.push(val);
            stack.display();
            break;
        case 2: 
            stack.pop();
            stack.display();
            break;
        case 3: 
            stack.display();
            break;
        
        default:
            cout<<"Invalid input\n";
            break;
        }
        cout<<"Do you want to try agin:- y for yes , n for no:- ";
        cin>>want;
    } while (want == 'y'|| want == 'Y');
    
    return 0;
}

