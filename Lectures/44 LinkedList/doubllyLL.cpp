#include <iostream>
using namespace std;

//class for Doubbly LL
class Node {
    public:
    int data;
    Node *prev;
    Node *next;

    //constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    };
};

// function to add node at the head;
void insertAtHead(Node* &head, int data){
    Node *temp = new Node(data);
    head->prev =  temp;
    temp->next = head;
    head = temp;
}
// function to add node at the tail/end;
void insertAtTail(Node* &head, int data){
    Node *itr = head;
    Node *temp = new Node(data);

    while (itr->next != NULL){
        itr = itr->next;
    }

    itr->next = temp;
    temp->prev = itr;    
}

// functtion to insert at any position 
void insertAtAnyPosition(Node* &head, int pos, int data){

    Node *nodeToInsert = new Node(data);

    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    int n = 1;
    Node *itr = head;
    Node *ahead  = itr->next;
    while(n < pos-1 ){
        itr = itr->next;
        n++;
    }
    
    if (itr->next == NULL)
    {
        insertAtTail(head, data);
        return;
    }
    
   nodeToInsert->next = itr->next;
   nodeToInsert->prev = itr;
   itr->next = nodeToInsert;
   ahead->prev = nodeToInsert;
}


//function to delete any node from the DLL
void deleteNode(Node* &head, int pos){

    if(pos == 1){ // head ko delete maar do
        Node *temp = head; 
        head = head->next;
        
        if (head != NULL){
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    //delete at any postion.
    int n = 1;
    Node *current = head;
    Node *previous = NULL;
    
    while (n <= pos - 1 ){
        previous = current;
        current = current->next;
        n++;
    }

    if(current->next == NULL){
        current->prev = NULL;
        previous->next = NULL;
        delete current;
    }
    else{
        Node *temp = current->next;
        previous->next = current->next;
        temp->prev = previous;

        current->next = NULL;
        current->prev = NULL;

        delete current;

    }
}



// function to print the Doubbly ll
void print(Node * &head){
    Node *itr = head;
    while (itr != NULL){
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << "\n" ;
}

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, 12);
    insertAtHead(head, 15);
    insertAtHead(head, 17);
    print(head);

    insertAtTail(head, 19);
    insertAtTail(head, 21);
    insertAtTail(head, 23);
    print(head);

    insertAtAnyPosition(head, 1, 45);
    print(head);

    insertAtAnyPosition(head, 9, 111);
    print(head);

    deleteNode(head, 4);
    print(head);
}