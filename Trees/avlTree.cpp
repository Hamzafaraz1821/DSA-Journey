//
// Created by hamza on 29/10/2023.
//

#include<iostream>
#include<iomanip>

using namespace std;

class avlTree{
private:
    struct Node{
        int data;
        Node* left;
        Node* right;
        int height;
    };
    Node* root;

    int height(Node* position){
        if(position==nullptr ){
            return -1;
        }else{
            return position->height;
        }
    }

    Node* SingleRotationWithRight(Node* K1);
    Node* DoubleRotationWithRight(Node* K1);
    Node *SingleRotationWithLeft(Node *K1);
    Node* DoubleRotationWithLeft(Node* K1);
    Node* insertNode(int,Node*);
    void printNode(Node*,int,string);
    void destroyNode(Node* node);
    Node* deleteNodeAt(int,Node*);
    Node* findMin(Node* rootNode){
    // Base case: the tree is empty or the node has no left child
    if(rootNode == nullptr || rootNode->left == nullptr){
        return rootNode;
    }
    // Recursively find the leftmost node in the left subtree
    return findMin(rootNode->left);
}




public:
    avlTree(){
        root = nullptr;
    }
    void deleteNode(int);
    void insert(int);
    void displayAll();
    ~avlTree(){
        destroyNode(root);
    }

};

void avlTree::insert(int X){
    root = insertNode(X , root);
}

avlTree::Node* avlTree::insertNode(int X, Node* rootNode){
    if(rootNode == nullptr){
        rootNode = new Node;
        rootNode->data = X;
        rootNode->height = 0;
        rootNode->left = rootNode->right = nullptr;
    }else{
        if(X > rootNode->data){
            rootNode->right = insertNode(X,rootNode->right);
            if(height(rootNode->right)- height(rootNode->left) == 2){
                if(X> rootNode->right->data){
                    rootNode = SingleRotationWithRight(rootNode);
                }else{
                    rootNode = DoubleRotationWithRight(rootNode);
                }
            }
        }else if(X < rootNode->data){
            rootNode->left = insertNode(X,rootNode->left);
            if(height(rootNode->left)- height(rootNode->right) == 2){
                if(X < rootNode->left->data){
                    rootNode = SingleRotationWithLeft(rootNode);
                }else{
                    rootNode = DoubleRotationWithLeft(rootNode);
                }
            }

        }
    }

    rootNode->height = max(height(rootNode->left), height(rootNode->right))+1;
    return rootNode;
}

avlTree::Node* avlTree::deleteNodeAt(int X,Node* rootNode){
    
    // Base case: the node to be deleted is not found or the tree is empty
    if(rootNode == nullptr){
        return rootNode;
    }
    // If the node to be deleted is smaller than the root node, then it lies in the left subtree
    if(X < rootNode->data){
        rootNode->left = deleteNodeAt(X, rootNode->left);
    }
    // If the node to be deleted is larger than the root node, then it lies in the right subtree
    else if(X > rootNode->data){
        rootNode->right = deleteNodeAt(X, rootNode->right);
    }
    // If the node to be deleted is equal to the root node, then this is the node to delete
    else{
        // Case 1: the node has no child or only one child
        if(rootNode->left == nullptr || rootNode->right == nullptr){
            Node* temp = rootNode->left ? rootNode->left : rootNode->right;
            // If the node has no child, then temp is nullptr
            if(temp == nullptr){
                temp = rootNode;
                rootNode = nullptr;
            }
            // If the node has one child, then copy the child's data to the node and delete the child
            else{
                *rootNode = *temp;
            }
            delete temp;
        }
        // Case 2: the node has two children
        else{
            // Find the inorder successor (smallest node in the right subtree)
            Node* temp = findMin(rootNode->right);
            // Copy the inorder successor's data to the node
            rootNode->data = temp->data;
            // Delete the inorder successor from the right subtree
            rootNode->right = deleteNodeAt(temp->data, rootNode->right);
        }
    }
    // If the tree had only one node, then return
    if(rootNode == nullptr){
        return rootNode;
    }
    // Update the height of the current node
    rootNode->height = max(height(rootNode->left), height(rootNode->right)) + 1;
    // Get the balance factor of the current node
    int balance = height(rootNode->left) - height(rootNode->right);
    // If the node is unbalanced, then perform rotations
    // Left-left case
    if(balance > 1 && height(rootNode->left->left) - height(rootNode->left->right) >= 0){
        return SingleRotationWithLeft(rootNode);
    }
    // Left-right case
    if(balance > 1 && height(rootNode->left->left) - height(rootNode->left->right) < 0){
        return DoubleRotationWithLeft(rootNode);
    }
    // Right-right case
    if(balance < -1 && height(rootNode->right->left) - height(rootNode->right->right) <= 0){
        return SingleRotationWithRight(rootNode);
    }
    // Right-left case
    if(balance < -1 && height(rootNode->right->left) - height(rootNode->right->right) > 0){
        return DoubleRotationWithRight(rootNode);
    }
    // Return the updated node
    return rootNode;
}


void avlTree::deleteNode(int val){
   root =  deleteNodeAt(val,root);
}

avlTree::Node* avlTree::SingleRotationWithRight(Node *K1) {
    Node* K2;

    K2 = K1->right;
    K1->right = K2->left;
    K2->left = K1;
    K1->height = max(height(K1->left), height(K1->right))+1;
    K2->height = max(height(K2->right),K1->height)+1;
    return K2;
}

avlTree::Node* avlTree::SingleRotationWithLeft(Node *K1) {
    Node* K2;

    K2 = K1->left;
    K1->left = K2->right;
    K2->right = K1;
    K1->height = max(height(K1->left), height(K1->right))+1;
    K2->height = max(height(K2->left),K1->height)+1;
    return K2;
}

avlTree::Node* avlTree::DoubleRotationWithRight(avlTree::Node *K1) {
    // Rotate K3 and K2;
    K1->right = SingleRotationWithLeft(K1->right);
    // Rotate K1 and K2
    return SingleRotationWithRight(K1);
}

avlTree::Node* avlTree::DoubleRotationWithLeft(avlTree::Node *K1) {
    K1->left = SingleRotationWithRight(K1->left);
    return SingleRotationWithLeft(K1);
}

void avlTree::printNode(avlTree::Node * root, int indent, string dir = "") {
    if(root == nullptr){
        return;
    }

    printNode(root->right,indent+8,"Right");

    cout << setw(indent) << "---|" << dir << "(" << root->data << ")" << endl << endl;

    printNode(root->left,indent+8,"Left");
}

void avlTree::displayAll(){
    printNode(root,0,"");
}


void avlTree::destroyNode(Node* node){
    if(node != nullptr){
        destroyNode(node->left);
        destroyNode(node->right);
        delete node;
    }
}


int main(){
    avlTree avl;
    int val;

    cout << endl << "Enter your Numbers: ";
    for(int i=0;i<10;i++){
        cin >> val;
        avl.insert(val);
    }

    

    avl.displayAll();


    return 0;
}
