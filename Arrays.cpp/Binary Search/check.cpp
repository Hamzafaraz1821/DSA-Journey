//
// Created by hamza on 23/10/2023.
//

#include <iostream>
#include<string>
#include <utility>
using namespace std;
// Patient class represent single Patient

class Patient{
protected:
    struct Node{
        string name;
        int age;
        int priority;

        Node* next;
    };

    Node* headPtr;
    Node* tailPtr;
};

class WaitingList : public Patient{
public:
    void addToWaitingList(string,int,int);
    void deleteFromWaitingList();
    void findPatientByName(string);
    void displayAllPatient();
};

void WaitingList::addToWaitingList(string name, int age, int priority) {
    Node* temp = tailPtr;

    Node* newNode = new Node;

    newNode->name = name;
    newNode->age = age;
    newNode->priority = priority;

    newNode->next = nullptr;

    if(tailPtr == nullptr){
        headPtr = newNode;
    }else{
        temp->next = newNode;
    }

    tailPtr = newNode;
}

void WaitingList::deleteFromWaitingList() {
    Node* temp = headPtr;

    if(headPtr == nullptr){
        cout << endl << "No Patient in the waiting list";
    }

    headPtr = temp->next;
    delete temp;
}

void WaitingList::findPatientByName(string name) {
    Node* temp = headPtr;
    bool flag = false;
    cout << name;

    if(headPtr == nullptr){
        cout << endl << "No Patient in the waiting list";
    }

    while(temp!=nullptr){
        if(temp->name == name){
            cout << endl << "Patient Found";
            cout << endl << "Patient Name: " << temp->name;
            cout << endl << "Patient Age: " << temp->age;
            cout << endl << "Patient Priority: " << temp->priority;
            flag = true;
            break;
        }
        temp = temp->next;
    }
    if(!flag){
        cout << endl << "Patient not found";
    }
    cout << endl;
}

void WaitingList::displayAllPatient() {
    cout << "displayAllPatient";
    Node* temp = headPtr;

    if(headPtr == nullptr){
        cout << endl << "No Patient in the waiting list";
    }
    while(temp!=nullptr){
        cout << endl << "Patient Name: " << temp->name;
        cout << endl << "Patient Age: " << temp->age;
        cout << endl << "Patient Priority: " << temp->priority;

        temp = temp->next;
    }
    cout << endl;
}

int main() {

    WaitingList list;

    list.addToWaitingList("Okasha",20,4);
    list.displayAllPatient();
    // list.findPatientByName("Okasha");
    list.addToWaitingList("Hamza",20,4);
    list.displayAllPatient();

    return 0;
}

