//
// Created by hamza on 02/10/2023.
//
//
// Created by hamza on 29/09/2023.
//

#include<iostream>
using namespace std;

class stack{
private:
    struct node{
        int data;
        node* next;
    };
    node* headPtr;
    node* tailPtr;
public:
    stack(){
        headPtr = nullptr;
        tailPtr = nullptr;
    }

    void push(int);
    int pop();
    void displayAll();

    // destructor function for linked list to free up memory;
    ~stack();

};

void stack::push(int val){
    node* newNode = new node;
    node* temp = headPtr;

    newNode->data = val;
    newNode->next = headPtr;

    if(headPtr == nullptr){
        tailPtr = newNode;
    }

    headPtr = newNode;


}

int stack::pop(){
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

void stack::displayAll() {
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




stack::~stack() {
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

    stack list1;

    list1.push(5);
    list1.push(6);

    list1.displayAll();

    int poped = list1.pop();

    cout <<endl <<  "The poped value is "<<poped;

    list1.displayAll();

    poped = list1.pop();

    cout <<endl <<  "The poped value is "<<poped;

    list1.displayAll();


    return 0;
}
