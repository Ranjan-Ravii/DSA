#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* createBST(Node* root, int data){
    if (root == nullptr){
       root = new Node(data);
        return root;
    }
    
    if (data < root->data){
        root->left = createBST(root->left, data);
    }
    else{
        root->right = createBST(root->right, data);
    }
    
    return root;

}

void takeData(Node* &root){
    int data;
    cin >> data;

    while (data != -1){
        root = createBST(root, data);
        cin >> data;
    }
    
}


// function to print bst in level order traversal
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
            if(!q.empty()){ 
                q.push(nullptr);  
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

//function for inorder traversal 
void inorderTraversal(Node* root){
    if (root == nullptr){
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " " ; 
    inorderTraversal(root->right);
    
}
//function for inorder traversal 
void preorderTraversal(Node* root){
    if (root == nullptr){
        return;
    }

    cout << root->data << " " ; 
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
}

//function for postorder traversal 
void postorderTraversal(Node* root){
    if (root == nullptr){
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " " ; 
    
}

// min max node on BST

Node* minValue(Node* root){
    Node * temp = root;

    while (temp -> left != nullptr){
        temp = temp->left;
    }
    
    return temp;
}
Node* maxValue(Node* root){
    Node * temp = root;

    while (temp -> right != nullptr){
        temp = temp->right;
    }
    
    return temp;
}
int inorderPredecessor(Node* root, int key, int &pred){
 
    if(root == nullptr){
        return 0;
    }

    inorderPredecessor(root->left, key, pred);
    if (root->data < key ){
        pred = root->data;
    }
    inorderPredecessor(root->right, key, pred);

    return pred;
}

int inorderSuccessor(Node* root, int key){
    int succ = -1;

    while (root) {
        if(root->data >  key){
            succ = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return succ;
}


int main() {
     
    Node* root = nullptr;
    cout << "Enter data to create bst" << endl ;
    takeData(root);
    

    cout << "\nlevel order  traversal" << endl;
    levelOfTravesal(root);

    cout << "\ninorder  traversal" << endl;
    inorderTraversal(root);

    cout << "\npreorder  traversal" << endl;
    preorderTraversal(root);

    cout << "\npostorder  traversal" << endl;
    postorderTraversal(root);

    cout << "\n" << endl;
    cout << "Minimum value in bst is : " << minValue(root)->data << endl;
    cout << "Maximum value in bst is : " << maxValue(root)->data << endl;



    int pred = -1;
    int key = 10;
    int predcessor = inorderPredecessor(root, key, pred);
    cout << "inorder predecessor of " <<  key << " : " << predcessor << endl ;

 
    int keySucc = 11;
    int successor = inorderSuccessor(root, keySucc);
    cout << "inorder successor of " <<  keySucc << " : " << successor << endl ;

    return 0;
}

