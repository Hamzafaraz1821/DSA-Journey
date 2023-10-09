//
// Created by hamza on 09/10/2023.
//

//
// Created by hamza on 09/10/2023.
//

#include<iostream>
#include<string>
using namespace std;

class queue{
private:
    struct node{
        string data;
        node* next;
    };
    node* headPtr;
    node* tailPtr;
public:
    queue(){
        headPtr = nullptr;
        tailPtr = nullptr;
    }

    void enqueue(string);
    string dequeue();
    int LengthOfString();
    bool isEmpty();
    void displayAll();

    // destructor function for linked list to free up memory;
    ~queue();

};

void queue::enqueue(string val){
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

string queue::dequeue(){
    node* temp = headPtr;

    if(headPtr == nullptr){
        cout <<endl << "Underflow there is no node";
        return "";
    }else{
        if(temp->next == nullptr){
            string data;
            headPtr = nullptr;
            data = temp->data;
            delete temp;
            return data;
        }else{
            string data = temp->data;
            headPtr = temp->next;
            delete temp;
            return data;
        }
    }
}

int queue::LengthOfString(){
    node* temp = headPtr;
    string str = temp->data;
    int length = str.length();
    return length;
}

bool queue::isEmpty(){
    if(headPtr == nullptr) return true;
    return false;
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



    list1.enqueue("Hamza");
    list1.enqueue("Faraz");
    list1.enqueue("Khan");

    list1.displayAll();

    while(!list1.isEmpty()){
        cout <<endl<< "Length is " << list1.LengthOfString() << " of the string: " << list1.dequeue() ;
    }

    list1.displayAll();



    return 0;
}

