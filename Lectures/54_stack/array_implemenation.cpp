#include <iostream>
using namespace std;

class Stack{
    public:
    int size;
    int top;
    int* array;

    //constructor
    Stack(int size){
        this->size = size;
        array = new int[size];
        top = -1;
    }

    void push(int element){
        // there is space available
        if(size - top > 1){
            top++;
            array[top] = element;
        }
        else{
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        // if stack is not empty, means there is alteast one element
        if (top >= 0){
           top--;
        }
        else{
            cout << "Stack Uderflow" << endl;
        }
        
    }

    bool empty(){
        if(top >= 0){
            return false;
        }
        else{
            return true;
        }
    }

    int peek(){
        if(top >= 0){
            return array[top];
        }else{
            return -1;
        }
    }
};



int main(){
    Stack st(5);

    st.push(12); 
    st.push(22); 
    st.push(32); 
    cout << st.peek() << endl;


    if(st.empty()){
        cout << "stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }
    
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;


}