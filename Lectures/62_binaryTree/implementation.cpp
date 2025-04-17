#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node* right;

    //constructor
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
//********************** function to build tree *********************
Node* buildTree(Node * root){
    cout << "Enter the data" << endl;
    int data ;
    cin >> data;
    root = new Node(data);

    //base case i.e -1 = nullptr
    if (data == -1){
        return nullptr; 
    }
    
    cout << "For left node of " << data << endl ;
    root->left = buildTree(root->left);
    cout << "For right node of " << data << endl ;
    root->right = buildTree(root->right);

    return root;
}    

//*************** LEVEL ORDER TRAVERSAL **************************

void levelOfTravesal(Node* root ){
    queue<Node*> q;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        //check for line break
        if(temp == nullptr){
            cout << endl;
            if(!q.empty()){ // there are still some child nodes
                q.push(nullptr);  //the nullptr will be placed after the cildren node, i.e line break for next iteration
            }
        }
        else{
            cout << temp->data << " " ;

            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
    
}

// ***************************** REVERSE LEVEL ORDER TRAVERSAL *****************************
 
void reverseLevelOrderTree(Node* root){
    queue<Node*> q;
    stack<int> st;

    q.push(root);
    q.push(nullptr);
    
    //store the node data in a stack
    while (!q.empty()){
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr){
            st.push(-1);
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            st.push(temp->data);
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }

    //create a reverse tree using stack's data.  
    while (!st.empty()){

        if(st.top() != -1){
            cout << st.top() << " " ;
        }
        else{
            cout << endl;
        }
        st.pop();
    }
}

//************************ inOrder preOrder postOrder  *********************
void inOrder(Node* root){  //LNR -> move to the left first till last, then print node and finally move to the right of the node
    if (root == nullptr){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    
}

void preOrder(Node* root){ // NLR
    if(root == nullptr){
        return;
    }

    cout << root->data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(Node* root){ // LRN
    if(root == nullptr){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";

}

// ********************* build binary tree using  order level traversal *******************

void buildfromOrderLevel(Node* &root){
    queue<Node*>q;
   
    cout << "Enter the data for root: " ;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "Enter the data for left of " << temp->data << " : " ;
        int leftData ;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the data for right of " << temp->data << " : " ;
        int rightData; 
        cin >> rightData;

        if (rightData != -1 ){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    Node * root = nullptr;

    /*
    // 1 3 7 -1 -1 11 -1 -1  5 17 -1 -1 -1
    root = buildTree(root);
    levelOfTravesal(root);

    cout << "Reversal of order level Tree : " << endl;
    reverseLevelOrderTree(root);

    cout << "\nInorder taversal : " << endl;
    inOrder(root);

    cout << "\nPreOrder taversal : " << endl;
    preOrder(root);

    cout << "\nPost order taversal : " << endl;
    postOrder(root);

    */

    buildfromOrderLevel(root);
    cout << "\n" << endl;
    levelOfTravesal(root);

}