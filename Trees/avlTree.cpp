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



public:
    avlTree(){
        root = nullptr;
    }
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

    cout << setw(indent) << "---|" << dir << root->data << endl;

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
