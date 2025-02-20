#include <iostream>
using namespace std;

//creating a class of Node
class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this ->data = data;
        this -> next = NULL;
    }

};

//function to insert data at the node of linked list.
void insertAtHead(Node* &head , int data){
    Node *temp = new Node(data);
    temp -> next = head;
    head = temp;
}

// function to insert data / node at tail
void insertAtTail(Node* &tail, int data){
    Node *temp = new Node(data);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

//Insert at any postion in LL
void insertAtPosition(Node* &head, Node* &tail, int pos, int data){

    //insert at 1st position
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }

    int n = 1;
    Node *temp = head;
    while ( n != pos-1){
        temp = temp->next;
        n++;
    }


    if(temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node *nodeToTndert = new Node(data);
    nodeToTndert -> next = temp->next;
    temp->next = nodeToTndert; 
    
}


// ********************** DELETION OF NODE ********************
void deleteNode(Node* &head, int pos){
   
    //delete head node or 1st node
    if (pos == 1){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{  
        int n = 1;
        Node *curr = head;
        Node *prev = NULL;
    
        while (n < pos){
            prev = curr;
            curr = curr->next;
            n++;
        }

        if (curr->next == NULL){
            prev->next = NULL;
            delete curr;
        }
        else{
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }    
    cout << "deletion of " << pos << "th node is successfull : "; 
}

//traversal in linkedlist 

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL){
        cout << temp->data << " " ;
        temp = temp->next;
    }
    
    cout << endl;
}


int main(){

    Node *node1 = new Node(1);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node* head = node1;
    Node *tail = node1;

    // insertAtHead(head, 12);
    // insertAtHead(head, 15);
    // insertAtHead(head, 17);
    // print(head);
    // cout << endl;
    cout << "insertion at tail " << endl;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    print(head);

    insertAtPosition(head,tail, 4, 15);
    print(head);

    deleteNode(head, 3);
    print(head);
    

    // cout << "head " << head->data << "::" << "tail " << tail->data << endl;
}