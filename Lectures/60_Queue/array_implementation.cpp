 
#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int qfront; 
    int rear;
    int size;

    public:
    Queue() { // constructor
        size = 1000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    // Enqueue function (no need for rear and data as parameters)
    void enqueue(int data) {
        if (rear == size) { 
            cout << "Queue is full." << endl;
        }
        arr[rear] = data;
        rear++;
    } 

    void dequeue() {
        if (qfront == rear) {  
            cout << "Queue is empty." << endl;
            return;
        }
        arr[qfront] = -1; // Remove the front element
        qfront++;
    
        if (qfront == rear) { // agar ye condition aata hai to reset kardo
            qfront = 0;
            rear = 0;
        }
    }

    // Front function to get the front element
    int front() {
        if (qfront == rear) {  
            return -1;
        }
        return arr[qfront];
    }

    // Back function to get the last element
    int back() {
        if (qfront == rear) {  
            return -1;
        }
        return arr[rear - 1];
    }

    // Check if queue is empty
    bool isEmpty() {
        return (qfront == rear); 
    }
};

int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    
    q.dequeue();
    
    cout << "Front element after dequeue: " << q.front() << endl;
    
    /*
        //lets talk about time complexity 
        enqueue -> O(1)
        dequeue -> O(1)
        front -> O(1)
        back -> O(1)
        size -> O(1)
    */
    

    return 0;
}
