#include <iostream>
using namespace std;


// implimentation of stack using linked list;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class Stack{
    private:
    Node* top;

    //constructor for stack
    public:
    Stack(){
        top = nullptr; // initialise an empty stack
    }

    void push(int element){
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if (top == nullptr){
            cout << "stack overflow" << endl;
            return;
        }
        
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if (top == nullptr){
            cout << "Stack is Empty!!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == nullptr;
    }


    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Stack elements: ";
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Stack after popping: ";
    s.display();

    return 0;
}