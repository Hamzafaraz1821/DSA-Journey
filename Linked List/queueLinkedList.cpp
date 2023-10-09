//
// Created by hamza on 09/10/2023.
//

#include<iostream>
using namespace std;

class queue{
private:
    struct node{
        int data;
        node* next;
    };
    node* headPtr;
    node* tailPtr;
public:
    queue(){
        headPtr = nullptr;
        tailPtr = nullptr;
    }

    void enqueue(int);
    int dequeue();
    void displayAll();

    // destructor function for linked list to free up memory;
    ~queue();

};

void queue::enqueue(int val){
    node* newNode = new node;
    node* temp = tailPtr;

    newNode->data = val;
    newNode->next = nullptr;

    if(tailPtr == nullptr){
        headPtr = newNode;
        tailPtr = newNode;
        return;
    }

    temp->next = newNode;
    tailPtr = newNode;
}

int queue::dequeue(){
    node* temp = headPtr;

    if(headPtr == nullptr){
        cout << "Underflow there is no node";
    }else{
        if(temp->next == nullptr){
            int data;
            headPtr = nullptr;
            data = temp->data;
            delete temp;
            return data;
        }else{
            int data = temp->data;
            headPtr = temp->next;
            delete temp;
            return data;
        }
    }
}

void queue::displayAll() {
    node* temp = headPtr;
    cout << endl;
    if(temp == nullptr){
        cout <<endl << "No node. Please add one!";
    }
    while(temp!= nullptr){
        cout << "->" << temp->data;
        temp = temp->next;
    }
}




queue::~queue() {
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

    queue list1;

    list1.enqueue(5);
    list1.enqueue(6);
    list1.enqueue(7);
    list1.enqueue(8);
    list1.enqueue(9);


    list1.displayAll();

    int value = list1.dequeue();
    cout << endl << "The Dequeued value is: " << value;
    list1.displayAll();


    return 0;
}
