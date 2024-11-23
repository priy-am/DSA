// Write a program to implement stack using array (Show all the operations like insertion, deletion and display)
#include <iostream>
using namespace std;
class stack
{
private:
    int top;
    int size;
    int* arr;
public:
    stack(int siz){
        size = siz;
        arr = new int[size];
        top = -1;
    };

    bool isFull(){
        return top == size -1;
    }

    bool isEmpty(){
        return top == -1;
    }
    
    //display
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<"Stack element:- \n";
        for(int i = 0; i<=top; i++){
            cout<<arr[i]<<", ";
        }
        cout<<endl;
}
    //push
    void push(int val){
        if(isFull()){
            cout<<"Stack overflow! Cannot push " << val << endl;
            return;
        }
        arr[++top] = val;
        
    }
    //pop
    int pop(){
        if(isEmpty()){
            cout<<"Stack underflow! Cannot pop." << endl;
            return 0;
        }
        int dltelement = arr[top--];
        cout << "Popped " << dltelement << " from stack." << endl;
        display();
        return dltelement;
    }

    ~stack(){
        delete[] arr;
    };
};


int main(int argc, char const *argv[])
{
    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;
    stack stackBook(stackSize);
    int data;
    cout<<"Enter the data of the stack:- ";
    for(int i = 0 ; i<stackSize; i++){
        cin>>data;
        stackBook.push(data);
    }
    stackBook.display();
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
            stackBook.push(val);
            stackBook.display();
            break;
        case 2: 
            stackBook.pop();
            // cout<<dltemenet<<" is pop form the array\n";
            break;
        case 3: 
            stackBook.display();
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
