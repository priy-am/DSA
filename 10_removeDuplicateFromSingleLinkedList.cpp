// Write a program to remove duplicates from the sorted linked list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {} // constructor
};
class LinkedList
{
private:
    Node *head;
public:
    LinkedList() : head(nullptr) {} // constructor
    //insert the element
    void insert(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* ptr = head;
        while(ptr->next!= nullptr){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    void removeDuplicates(){
        if(!head){
            return;
        }
        Node* ptr = head;
        while(ptr && ptr->next){
            if(ptr->data == ptr->next->data){
                Node* ptr1 = ptr->next;
                ptr->next = ptr1->next;
                delete ptr1;
            }else{
                ptr = ptr->next;
            }
        }
    }
    //display
    void display(){
        Node* ptr = head;
        while(ptr!=nullptr){
            cout<<ptr->data<<"->  ";
            ptr = ptr->next;
        }
        cout<<"Null\n";
    }
    // deconstructor
    ~LinkedList(){
        Node *temp;
        while (head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main(int argc, char const *argv[])
{
    LinkedList list;
    list.insert(1);
    list.insert(1);
    list.insert(2);
    list.insert(2);
    list.insert(3);
    list.insert(3);
    list.insert(3);
    list.insert(3);
    list.insert(4);
    list.insert(4);
    cout << "Original List: ";
    list.display();
    list.removeDuplicates();
    cout << "List after removing duplicates: ";
    list.display();
    return 0;
}
