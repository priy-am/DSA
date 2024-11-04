// Q11. Write a program to swap nodes in a linked list without swapping data

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *Next;
    Node(int val) : data(val), Next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // insert
    void append(int data){
        Node *newNode = new Node(data);
        if (head == nullptr){
            head = newNode;
            return;
        }
        Node *ptr = head;
        while (ptr->Next != nullptr){
            ptr = ptr->Next;
        }
        ptr->Next = newNode;
    }

    // swap the linked list
    void swapNodes(int x, int y){
        if (x == y) return;

        Node *prevX = nullptr, *currX = head;
        while (currX && currX->data != x) {
            prevX = currX;
            currX = currX->Next;
        }

        Node *prevY = nullptr, *currY = head;
        while (currY && currY->data != y) {
            prevY = currY;
            currY = currY->Next;
        }

        if (!currX || !currY) return; //return when the element not find there
        if (prevX) {
            prevX->Next = currY;
        } else {
            head = currY;
        }

        if (prevY) {
            prevY->Next = currX;
        } else {
            head = currX;
        }

         Node* temp = currY->Next;
        currY->Next = currX->Next;
        currX->Next = temp;
    }

    void display(){
        Node *ptr = head;
        while (ptr != nullptr){
            cout << ptr->data << "->";
            ptr = ptr->Next;
        }
        cout << "Null\n";
    }

    ~LinkedList(){
        Node *temp;
        while (head != nullptr){
            temp = head;
            head = head->Next;
            delete (temp);
        }
    };
};

int main(int argc, char const *argv[])
{
    int num, data;
    LinkedList list;
    cout << "Enter the number of element in there in linked list :- ";
    cin >> num;
    cout<<"Enter the element of the list :- ";
    for (int i = 1; i <= num; i++){
        cin >> data;
        list.append(data);
    }
    cout << "Display the list \n";
    list.display();
    int x, y;
    cout << "Enter the swaping the element x and y :- ";
    cin >> x >> y;
    list.swapNodes(x, y);
    cout << "Display after swap the list \n";
    list.display();

    return 0;
}
