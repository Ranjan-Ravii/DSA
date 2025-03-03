#include <iostream>
#include <queue>
using namespace std;

//function to print queue

void print(){

}

int main(){

    queue<int> q; // creation of queue

    // operations on queue
    q.push(2);
    q.push(4);
    q.push(6);

    cout << "sieze of queue : " << q.size() << endl;
    q.pop();
    cout << "sieze of queue : " << q.size() << endl;

    if(q.empty()){
        cout << "queue is empty." << endl;
    }else{
        cout << "queue is not empty." << endl;
    }

    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;

}