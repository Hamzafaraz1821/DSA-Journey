//
// Created by hamza on 23/10/2023.
//

#include<iostream>
using namespace std;


class doublyLinked{
    struct Node{
        int data;
        Node* next;
        Node* prev;
    };
    Node* headPtr;
    Node* tailPtr;

public:
    Node* getHead(){
        return headPtr;
    }
    void addNodeAtHead(int);
    Node* swap(Node* );
    Node* reverseDLL(Node* );
    void displayAll();
};

doublyLinked::Node* doublyLinked::swap(Node* head){
    if(head == nullptr || (head->next == nullptr && head->prev != nullptr)){
        return head;
    }

    Node* first = head;
    Node* second = head->next;
    Node* third = second->next;

    if(head == headPtr){
        second->prev = nullptr;
        headPtr = second;
    }

    second->next = first;
    first->prev = second;
    first->next = swap(third);

    return second;
}

doublyLinked::Node* doublyLinked::reverseDLL(doublyLinked::Node * head)
{
    // Write your code here
    Node* temp = nullptr;
    while(head->next){
        temp = head->prev;
        head->prev = head->next;
        head->next = temp;
        head = head->next;
    }
    head->next = head->prev;
    head->prev = nullptr;

    headPtr = head;
    return head;
}

void doublyLinked::addNodeAtHead(int value) {
    Node* newNode = new Node;

    if(headPtr == nullptr){
        tailPtr = newNode;

        newNode->data = value;
        newNode->next = headPtr;
        newNode->prev = headPtr;
    }else {
        newNode->data = value;
        newNode->next = headPtr;
        newNode->prev = nullptr;
        headPtr->prev = newNode;
    }

    headPtr = newNode;
}

void doublyLinked::displayAll(){
    Node* temp = headPtr;
    while(temp!= nullptr){
        cout << "->" << temp->data;
        temp = temp->next;
    }
}


int main(){

    doublyLinked doubl{};

    doubl.addNodeAtHead(5);
    doubl.addNodeAtHead(4);
    doubl.addNodeAtHead(3);
    doubl.addNodeAtHead(2);
    doubl.addNodeAtHead(1);

//    doubl.swap(doubl.getHead());
    doubl.reverseDLL(doubl.getHead());

    doubl.displayAll();
    return 0;
}
