#include <iostream>
#include <map>
using namespace std;

// implementaiton of circular linked list.
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Distructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for the node with data " << value << endl;
    }
};

// function to print the node data

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 
// function to insert at the head.
// taking tail so that we have access for both tail and its next that is head. though there is no such node defined as head or tail
void inserANode(Node *&tail, int element, int data){

    // if there is no node present
    if (tail == NULL){
        Node *temp = new Node(data);
        tail = temp;
        temp->next = tail;
    }
    else{
        /* by this code you can insert at fist node in reverse order without using element in function's argument. 
            // Node *newNode = new Node(data);
            // Node *curr = tail;
            // Node *pointer = curr->next;
            // curr->next = newNode;
            // newNode->next = pointer;
            // tail = tail->next;
        */
        

        Node* curr = tail;
        while (curr->data != element){
            curr = curr->next;
        }

        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
        
    }
}


// function to delete the node from the circular linked list
void deleteNode(Node* &tail, int element){
    if(tail == NULL){ //case 1. agar node hi na ho
        cout << "List is empty!!" << endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;
        
        while(curr -> data != element) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        
        // 1 node linked list
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

bool isCirclar(Node* tail){

    if(tail == NULL){
        return false;
    }

    Node* itr = tail;

    while (itr->next != NULL && itr->next == tail){
        itr = itr->next;
    }

    if(itr == tail){
        return true;
    }
    
    return false;

}

bool detectCircular(Node* tail){
    map <Node*,bool> visited;

    if(tail == NULL){ //empty list
        return false;
    }
   
    Node* temp = tail;

    while (temp != NULL){
        if (visited[temp] == true){
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}


int main()
{
    Node *tail = NULL;
    inserANode(tail, 12, 10);
    print(tail);
    inserANode(tail,10, 12);
    print(tail);
    inserANode(tail,12, 14);
    print(tail);
    inserANode(tail,14, 24);
    print(tail);
    inserANode(tail,10, 80);
    print(tail);

    cout << "value of tail node : " << tail->data << endl;



    deleteNode(tail, 12);
    print(tail);

    
    if(isCirclar(tail)){
        cout << "the LL is circular." << endl;
    }
    else{
        cout << "the LL is not circular." << endl;

    }

     
    if(detectCircular(tail)){
        cout << "the LL is circular." << endl;
    }
    else{
        cout << "the LL is not circular." << endl;

    }
}