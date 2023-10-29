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

public:
    avlTree(){
        root = nullptr;
    }
    void insert(int);
    void displayAll();

};

void avlTree::insert(int X){
    root = insertNode(X , root);
}

avlTree::Node* avlTree::insertNode(int X, Node* root){
    if(root == nullptr){
        root = new Node;
        root->data = X;
        root->height = 0;
        root->left = root->right = nullptr;
    }else{
        if(X > root->data){
            root->right = insertNode(X,root->right);
            if(height(root->right)- height(root->left) == 2){
                if(X> root->right->data){
                    root = SingleRotationWithRight(root);
                }else{
                    root = DoubleRotationWithRight(root);
                }
            }
        }else if(X < root->data){
            root->left = insertNode(X,root->left);
            if(height(root->left)- height(root->right) == 2){
                if(X < root->left->data){
                    root = SingleRotationWithLeft(root);
                }else{
                    root = DoubleRotationWithLeft(root);
                }
            }

        }
    }

    root->height = max(height(root->left), height(root->right))+1;
    return root;
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
    K1->right = SingleRotationWithLeft(K1->right);
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
