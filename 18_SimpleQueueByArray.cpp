// Write a program to implement Simple Queue using arrays (Show all the operations like insertion, deletion and display)

#include <iostream>
using namespace std;

class simpleQueue
{
private:
    int front, rear, size;
    int* queue;
public:
    simpleQueue(int s):size(s),front(-1),rear(-1){
        queue = new int [size];
    }

    bool isfull(){
        return rear == size-1;
    }

    bool isEmpty(){
        return front == -1|| front>rear;
    }


    void display(){
        if(isEmpty()){
            cout<<"Queue is empty!\n";
            return;
        }
        for(int i = front; i<= rear; i++){
            cout<<queue[i]<<", ";
        }
        cout<<endl;
    }

    void enqueue(int val){
        if(isfull()){
            cout<<"Queue overflow! Cannot enqueue " << val << endl;
            return;
        }
        if(front ==-1){
            front ++;
        }
        rear++;
        queue[rear]= val;
        display();
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is underflow! cannot dequeue\n";
            return;
        }
        front++;
        display();
    }



    ~simpleQueue(){
        delete[] queue;
    }
};


int main(int argc, char const *argv[])
{
    int queueSize;
    cout << "Enter the size of the queue: ";
    cin >> queueSize;

    simpleQueue queue(queueSize);

    int choice;
    char want;
    do {
        cout << "Enter choice:\n1. Enqueue\n2. Dequeue\n3. Display\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                
                break;
            case 2:
                queue.dequeue();
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
