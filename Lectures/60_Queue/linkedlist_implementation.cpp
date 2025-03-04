#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;
};

// Queue class
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Enqueue function to insert an element into the queue
    void enqueue(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue function to remove an element from the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1; // Indicating an error
        }

        Node *temp = front;
        int data = front->data;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        return data;
    }

    // Peek function to get the front element without dequeuing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1; // Indicating an error
        }
        return front->data;
    }

    // Destructor to clean up memory
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

// Main function to test the queue
int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element after dequeue: " << q.peek() << endl;

    q.enqueue(40);
    cout << "Front element after enqueue: " << q.peek() << endl;

    return 0;
}
