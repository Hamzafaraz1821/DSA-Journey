#include <iostream>
#include<iomanip>
#include <vector>
#include<queue>

using namespace std;

class Tree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {} // Add constructor to Node struct
    };
    Node* root;

    void addNode(Node*&,int val);
    bool search(Node*,int);
    Node* deleteIt(Node*&,int);

public:
    Tree() {
        root = nullptr;
    }

    Node * getHead(){
        return root;
    }

    void insertNode(int);
    void diagonalPrint(Node *root);
    void deleteNode(int val);
    void searchNode(int val); // Change return type to bool
    void displayAllNodes(); // Use a wrapper function to call the recursive function
    void printNode(Node* node, int indent,string);

};

void Tree::insertNode(int val){
    addNode(root,val);
}

void Tree::addNode(Node*& root,int val) {
    if (root == nullptr) {
        Node* newNode = new Node(val);
        root = newNode;
        return;
    }

    if(val < root->data){
        addNode(root->left,val);
    }else{
        addNode(root->right,val);
    }
}

void Tree::diagonalPrint(Node *root) {
    if(root == nullptr){
        return;
    }

    queue<Node*> queue1;
    queue1.push(root);

    while(!queue1.empty()){
        Node* current = queue1.front();
        queue1.pop();

        while(current){
            cout << current->data << ",";

            if(current->left){
                queue1.push(current->left);
            }

            current = current->right;
        }
    }
}

bool Tree::search(Node* root,int val){
    if(root == nullptr){
        return false;
    }

    if(val > root->data){
        return search(root->right,val);
    }else if(val < root->data){
        return search(root->left,val);
    }else{
        return true;
    }
}

void Tree::searchNode(int val) {
     bool isFound = search(root,val);
     if(isFound){
         cout << endl << "Found!";
     }else{
         cout << endl << "Not Found!";
     }
}

Tree::Node* Tree::deleteIt(Node*& root, int val) {
    if(root == nullptr){
        return root;
    }

    if(val > root->data){
        root->right = deleteIt(root->right,val);
        return root;
    }else if(val < root->data){
        root->left = deleteIt(root->left,val);
        return root;
    }

    if(root->left == nullptr){
        Node* temp = root->right;
        delete root;
        return temp;
    }else if(root->right == nullptr){
        Node* temp = root->left;
        delete root;
        return temp;
    }else{
        Node* successorRoot = root;
        Node* successor = root->right;

        while(successor->left != nullptr){
            successorRoot = successor;
            successor = successor->left;
        }

        if(successorRoot != root){
            successorRoot->left = successor->right;
        }else{
            successorRoot->right = successor->right;
        }

        root->data = successor->data;
        delete successor;
        return root;
    }
}

void Tree::deleteNode(int val) {

    if(!search(root,val)){
        cout <<endl << "Value to be deleted is not Found";
    }else{
        deleteIt(root,val);
    }

}

void Tree::printNode(Node* node, int indent, string dir = "") {
    if (node == nullptr) {
        return;
    }

    printNode(node->right, indent + 8, "Right ");

    cout << setw(indent) << "----|" << dir << node->data << endl << endl;

    printNode(node->left, indent + 8, "Left ");
}


// This function prints the whole tree by calling the printNode function on the root
void Tree::displayAllNodes() {
    printNode(root, 0);
}

int main() {
    Tree binaryTree;


        bool exit = false;
        while(!exit){
           cout << endl << "Choose from Option: ";
           cout << endl << "1. Add a Node\n2. Add Many Nodes\n3. Display Nodes\n4. Delete a Node\n5. Exit\n";
           int option;
           cin >> option;
           switch(option){
                case 1:{
                     int value;
                     cout << endl << "Enter your number: ";
                     cin >> value;
                     binaryTree.insertNode(value);
                     break;
                }
                case 2:{
                     cout << endl << "Enter the limit of numbers you want to enter: ";
                     int size;
                     cin >> size;
                     vector<int> values(size);
                     cout << endl << "Enter your numbers: ";
                     for(int i=0; i<size; i++) {
                          cin>>values[i];
                     }
                     for(int i=0; i<size; i++){
                            binaryTree.insertNode(values[i]);
                     }
                     break;
                }
                case 3:{
                     binaryTree.displayAllNodes();
                     break;
                }
                case 4:{
                    int value;
                    cout << "Value to check: ";
                    cin >> value;
                    binaryTree.searchNode(value);
                    break;
                }
                case 5:{
                     int value;
                     cout << endl << "Enter the number you want to delete: ";
                     cin >> value;
                     binaryTree.deleteNode(value);
                     break;
                }
                case 6:{
                     exit = true;
                     break;
                }
                default:{
                     cout << endl << "Invalid Option";
                     break;
                }
           }
        }

        binaryTree.diagonalPrint(binaryTree.getHead());


    return 0;
}
