//
// Created by hamza on 02/10/2023.
//

// check if the parenthesis are balanced or not

#include<iostream>
using namespace std;


class linkedList{
private:
    struct node{
        char data;
        node* next;
    };
    node* headPtr;
    node* tailPtr;
public:
    linkedList(){
        headPtr = nullptr;
        tailPtr = nullptr;
    }

    void push(char);
    char pop();
    void displayAll();

    // destructor function for linked list to free up memory;
    ~linkedList();

};

void linkedList::push(char val) {
    node* newNode = new node;
    newNode->data = val;
    newNode->next = headPtr;
    if(headPtr == nullptr){
        tailPtr = newNode;
    }

    headPtr = newNode;
}

char linkedList::pop(){
    node* temp = headPtr;

    if(headPtr == nullptr){
        cout << "Underflow there is no node";
    }else{
        if(temp->next == nullptr){
            char data;
            headPtr = nullptr;
            data = temp->data;
            delete temp;
            return data;
        }else{

            char data = temp->data;
            headPtr = temp->next;
            delete temp;
            return data;
        }
    }
}



void linkedList::displayAll() {
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

string isBalanced(const string& input){

    linkedList list1;
    int count=0;
    for(char i:input){
        list1.push(i);
        ++count;
    }
    string reverse;
    for(int i=0; i<count; i++){
        reverse+=list1.pop();
    }

    return reverse;
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


    string parenthesis = "Hamza";
    string val = isBalanced(parenthesis);

    cout << "Reverse is: " << val;

    return 0;
}
