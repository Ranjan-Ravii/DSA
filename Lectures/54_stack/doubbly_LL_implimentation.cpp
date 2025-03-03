#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Stack
{

private:
    Node *top;

public:
    Stack(){ // constructor of empty stack
        top = nullptr;
    }

    void push(int data){
        Node *newNode = new Node(data);
        if (top == nullptr)
        {
            top = newNode;
        }
        else
        {
            newNode->prev = top;
            top->next = newNode;
            top = newNode;
        }
    }

    void pop(){
        if (top == nullptr)
        {
            cout << "Stack underflow" << endl;
            return;
        }

        Node *temp = top;
        top = temp->prev;
        top->next = nullptr;
        delete temp;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    int peek() {
        if (top == nullptr)
        {
            cout << "Stack is empty!!" << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);


    cout << "Stack elements: ";
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Stack after popping: ";
    s.display();

    return 0;
}