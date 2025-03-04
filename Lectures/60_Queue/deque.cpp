#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
class Deque{
    int size;
    int front;
    int rear;
    int *arr;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;

    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check if queue is full
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear != size -1){
            front = size -1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull()){
            return false;
        }
        else if(isEmpty()){
            rear = front= 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){
            return -1; 
        }
        int poppedElement = arr[front];
        arr[front] = -1;

        if(front ==  rear){
            front = rear = -1;
        }
        else if(front == size - 1){
            front = 0;
        }else{
            front++;
        }
        return poppedElement;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()){
            return -1; 
        }
        int poppedElement = arr[rear];
        arr[rear] = -1;

        if(front ==  rear){
            front = rear = -1;
        }
        else if(rear == 0){
            rear = size - 1;
        }else{
            rear--;
        }
        return poppedElement;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }

        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }

        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1 ){
            return true;
        }
        return false;

    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) )){
            return true;
        }
        return false;
    }
};



    
    int main() {
        // Create a deque of size 5
        Deque dq(5);
    
        // Test pushFront
        cout << (dq.pushFront(10) ? "Inserted 10 at front\n" : "Failed to insert at front\n");
        cout << (dq.pushFront(20) ? "Inserted 20 at front\n" : "Failed to insert at front\n");
    
        // Test pushRear
        cout << (dq.pushRear(30) ? "Inserted 30 at rear\n" : "Failed to insert at rear\n");
        cout << (dq.pushRear(40) ? "Inserted 40 at rear\n" : "Failed to insert at rear\n");
        cout << (dq.pushRear(50) ? "Inserted 50 at rear\n" : "Failed to insert at rear\n");
    
        // Try inserting into a full deque
        cout << (dq.pushRear(60) ? "Inserted 60 at rear\n" : "Deque is full!\n");
    
        // Get front and rear elements
        cout << "Front element: " << dq.getFront() << endl;
        cout << "Rear element: " << dq.getRear() << endl;
    
        // Pop front and rear elements
        cout << "Popped from front: " << dq.popFront() << endl;
        cout << "Popped from rear: " << dq.popRear() << endl;
    
        // Insert again to check circular behavior
        cout << (dq.pushFront(70) ? "Inserted 70 at front\n" : "Failed to insert at front\n");
        cout << (dq.pushRear(80) ? "Inserted 80 at rear\n" : "Failed to insert at rear\n");
    
        // Final state
        cout << "Front element: " << dq.getFront() << endl;
        cout << "Rear element: " << dq.getRear() << endl;
    
        return 0;
    }
    

