// Write a program to implement Circular Queue using arrays (Show all the operations like insertion, deletion and display)
#include <iostream>
using namespace std;
class circularQueue
{
private:
    int front, rear, size;
    int* queue;
public:
    circularQueue(int s):size(s),front(-1),rear(-1){
        queue = new int[size];
    }
    bool isFull() {
        return (front == 0 && rear == size-1)|| (rear +1 == front );
    }
    

    bool isEmpty(){
        return front == -1 ;
    }

    void enqueue(int val){
        if(isFull()){
            cout<<"Queue is full! Cannot enqueue " << val << endl;
            return;
        }
        if(isEmpty()){
            front = 0 ;
        }
        if(rear == size-1){
            rear = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = val;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        if (front == rear) { // If only one element is left
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size; // Wrap around if needed
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"queue is empty!\n";
            return;
        }
        if(rear>= front){
            for(int i = front ; i<= rear; i++){
                cout<<queue[i]<<", ";
            }
        }else{
            for(int i = front; i< size; i++){
                cout<<queue[i]<<", ";
            }
            for(int i = 0; i<= rear; i++){
                cout<<queue[i]<<", ";
            }
        }
        cout<<endl;
    }

    ~circularQueue(){
        delete[] queue;
    }

};

int main(int argc, char const *argv[])
{
    int queueSize;
    cout << "Enter the size of the queue: ";
    cin >> queueSize;

    circularQueue queue(queueSize);
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
