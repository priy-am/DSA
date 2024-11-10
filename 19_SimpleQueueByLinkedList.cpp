// Write a program to implement Simple Queue using linked lists. (Show all the operations like insertion, deletion and display)
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){}
};

class simpleQueue
{
private:
    Node* front;
    Node* rear;
public:
    simpleQueue():front(nullptr),rear(nullptr){}

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"queue is underflow! can't dequeue\n";
            return;
        }
        Node* temp = front; 
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return;
        }
        Node* ptr = front;
        while(ptr != nullptr){
            cout<<ptr->data<<", ";
            ptr  = ptr->next;
        }
        cout<<endl;
    }

    ~simpleQueue(){
        while(!isEmpty()){
            dequeue();
        }
    }
};

int main(int argc, char const *argv[])
{
    simpleQueue queue;

    int choice, value;
    char want;
    do {
        cout << "Enter choice:\n1. Enqueue\n2. Dequeue\n3. Display\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                queue.display();
                break;
            case 2:
                queue.dequeue();
                queue.display();
                break;
            case 3:
                queue.display();
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }

        cout << "Do you want to perform another operation? (y for yes, n for no): ";
        cin >> want;
    } while (want == 'y' || want == 'Y');

    return 0;
}
