//
// Created by hamza on 02/10/2023.
//

// check if the parenthesis are balanced or not

#include<iostream>
using namespace std;


class charStack{
private:
    struct node{
        char data;
        node* next;
    };
    node* headPtr;
    node* tailPtr;
public:
    charStack(){
        headPtr = nullptr;
        tailPtr = nullptr;
    }

    void push(char);
    char pop();
    void displayAll();

    // destructor function for linked list to free up memory;
    ~charStack();

};

void charStack::push(char val) {
    node* newNode = new node;

    if(headPtr == nullptr){
        tailPtr = newNode;
    }

    newNode->data = val;
    newNode->next = headPtr;

    headPtr = newNode;
}

char charStack::pop(){
    node* temp = headPtr;

    if(headPtr == nullptr){
        cout << "Underflow there is no node";
        return -1;
    }else{
        char data;
        if(temp->next == nullptr){
            headPtr = nullptr;
            data = temp->data;
            delete temp;
            return data;
        }else{
            data = temp->data;
            headPtr = temp->next;
            delete temp;
            return data;
        }
    }
}



void charStack::displayAll() {
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

bool isBalanced(const string& parenthesis){

    charStack list1;
    int count=0 , openCount=0 , closeCount=0;
    for(char i:parenthesis){
        list1.push(i);
        ++count;
    }

    list1.displayAll();


    // if count is not even it means that there is a closing or opening bracket missing from the pair
    if(count%2!=0){
        return false;
    }else{
        int i=0;
        char bracket = parenthesis[count-1];
        for(; i<(count/2);i++){
            if( list1.pop() != bracket){
                break;
            }
            ++openCount;
        }
        for(;i<count; i++){
            if(list1.pop() == bracket){
                break;
            }
             ++closeCount;
        }
    }
    cout << openCount << " " << closeCount;
    if(openCount == closeCount){
        return true;
    }else{
        return false;
    }


}


charStack::~charStack() {
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


    string parenthesis = "()()";
    bool val = isBalanced(parenthesis);

    if(val){
        cout <<endl<< "Is Balanced";
    }else{
        cout <<endl<< "Not Balanced";
    }

    charStack list1;
    list1.displayAll();


    return 0;
}
