//
// Created by hamza on 29/09/2023.
//

#include<iostream>
using namespace std;

class linkedList{
private:
    struct node{
        int data;
        node* next;
    };
    node* headPtr;
    node* tailPtr;
public:
    linkedList(){
        headPtr = nullptr;
        tailPtr = nullptr;
    }
    void addAtHead(int);
    void addAtTail(int);
    void deleteNode(int);
    void displayAll();

    // destructor function for linked list to free up memory;
    ~linkedList();

};

void linkedList::addAtHead(int val) {
    node* newNode = new node;
    newNode->data = val;
    newNode->next = headPtr;
    if(headPtr == nullptr){
        tailPtr = newNode;
    }

    headPtr = newNode;
}

void linkedList::addAtTail(int val){
     node* newNode = new node;
     node* temp = tailPtr;

    newNode->data = val;
    newNode->next = nullptr;

     if(headPtr == nullptr){
         headPtr = newNode;
     }

     if(tailPtr != nullptr) {
         temp->next = newNode;
     }

     tailPtr = newNode;
}

void linkedList::deleteNode(int val){
     node* temp = headPtr;

     while(temp != nullptr && temp->data!=val){
         temp = temp->next;
     }

     if(temp == nullptr){
         cout << endl << "Node not found";
     }else{
             temp->data = temp->next->data;
             temp->next = temp->next->next;

     }
     delete temp;

}

void linkedList::displayAll() {
    node* temp = headPtr;
    while(temp!= nullptr){
        cout << "->" << temp->data;
        temp = temp->next;
    }
}




linkedList::~linkedList() {
    node* temp = headPtr;
    while(temp!= nullptr){
        node* next = temp->next;
        delete temp;
        temp = next;
    }
    headPtr = nullptr;
    tailPtr = nullptr;
}

int main(){

    linkedList list1;

    list1.addAtTail(5);
    list1.addAtTail(6);
    list1.addAtTail(7);
    list1.addAtTail(8);
    list1.addAtTail(5);
    list1.addAtHead(4);
    list1.addAtTail(3);

    list1.displayAll();

    list1.deleteNode(8);

    list1.displayAll();

    return 0;
}
