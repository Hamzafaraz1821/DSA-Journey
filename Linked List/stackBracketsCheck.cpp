//
// Created by hamza on 26/10/2023.
//

#include<iostream>
using namespace std;

class stack{
private:
    struct node{
        char data;
        node* next;
    };
    node* headPtr;
    node* tailPtr;
public:
    stack(){
        headPtr = nullptr;
        tailPtr = nullptr;
    }


    void push(char);
    char pop();
    void displayAll();
    bool isEmpty();

    // destructor function for linked list to free up memory;
    ~stack(){
        while(!isEmpty()){
            pop();
        }
    }

};

bool stack::isEmpty() {
    return headPtr == nullptr;
}

void stack::push(char val){
    node* newNode = new node;
    node* temp = headPtr;

    newNode->data = val;
    newNode->next = headPtr;

    if(headPtr == nullptr){
        tailPtr = newNode;
    }

    headPtr = newNode;


}

char stack::pop(){
    node* temp = headPtr;

    if(isEmpty()){
        throw underflow_error("Stack is empty");
    }

    char data = temp->data;

    if(temp->next == nullptr){
        headPtr = nullptr;
        tailPtr = nullptr;
    }else{
        headPtr = temp->next;
    }

    delete temp;
    return data;
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



class balancingSymbols:public stack{
private:
    bool isBracket(char ch){
        if(ch == '(' || ch == '{' || ch == '['){
            return true;
        }
        return false;
    }

public:
    bool isBracketBalanced(string brackets);

};

bool balancingSymbols::isBracketBalanced(string brackets){
    if(brackets.empty() && isEmpty()){
        return true;
    }

    if(isBracket(brackets[0])){
        push(brackets[0]);
    }else{
        if(isEmpty()){
            return false;
        }
            char poppedChar = pop();
            if((poppedChar == '(' && brackets[0] != ')') ||
               (poppedChar == '{' && brackets[0] != '}') ||
               (poppedChar == '[' && brackets[0] != ']')){
                return false;
            }

    }
    return isBracketBalanced(brackets.substr(1));
}


int main(){

    balancingSymbols brackets;

    bool isBalanced = brackets.isBracketBalanced("[()]}");
    if(isBalanced){
        cout <<endl<< "The brackets are Consistent";
    }else{
        cout << endl << "The brackets are inConsistent";
    }
    return 0;
}
