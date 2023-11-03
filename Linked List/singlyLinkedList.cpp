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
    node* reverse(node*);

    void reverseList(){
        headPtr = reverse(headPtr);
    }
//    void swap(node* headPtr1,node* prev);
    node * swap(node* headPtr1);
    int noOfNodes(node* headPtr1){
        node* temp = headPtr1;
        int counter=0;
        while(temp!=nullptr){
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    node* getHead(){
        return headPtr;
    }

    void PrintLots(node* headPtr1 , node* headPtr2);

    // destructor function for linked list to free up memory;
    ~linkedList();

};

//void linkedList::swap(node* head,node* prev){
//    // Base case: if the list is empty or has only one node, return
//    if (head == nullptr || head->next == nullptr) {
//        return;
//    }
//    // Swap the current and next elements by changing the pointers
//    node* first = head;
//    node* second = head->next;
//
//    if (head == headPtr) {
//        headPtr = second;
//        prev = first;
//    }
//
//    node* third = second->next;
//    second->next = first;
//    first->next = third;
//    if(head != headPtr){
//        prev->next = second;
//    }
//    prev = first;
//    // Recursively swap the remaining elements
//    swap(third,prev);
//
//}


linkedList::node* linkedList::reverse(node* head) {
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}


linkedList::node* linkedList::swap(node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }

    node* first = head;
    node* second = head->next;
    node* third = second->next;
    if(head == headPtr){
        headPtr = second;
    }

    second->next = first;
    first->next = swap(third);

    return second;
}





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

void linkedList::PrintLots(node* headPtr1 , node* headPtr2){
    node* temp1 = headPtr1;
    node* temp2 = headPtr2;
    int i = 1;

    while(temp1 != nullptr && temp2 != nullptr){
        if(i == temp2->data){
            cout << temp1->data << " ";
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        i++;
    }
}


//void linkedList::PrintLots(node* headPtr1 , node* headPtr2){
//        node* temp1 = headPtr1;
//        node* temp2 = headPtr2;
//        int i=1;
//        int l = temp2->data;
//        while(temp1!=nullptr && temp2!= nullptr){
//                int value = temp2->data;
//
//                if(i == value){
//                    cout << endl << "value of i: "<< i<<endl;
//                    for(int k=l; (k<value-1 && k< noOfNodes(headPtr1)); k++){
//                        temp1 = temp1->next;
//                    }
//                    if(temp1 == nullptr){
//                        cout << "There end of list is reached.";
//                        break;
//                    }
//                    cout << temp1->data << " ";
//                    temp1 = temp1->next;
//                    temp2 = temp2->next;
//                    l=value;
//                }
//                i++;
//
//        }
//}





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

    linkedList list1,list2;

    list1.addAtTail(1);
    list1.addAtTail(2);
    list1.addAtTail(3);
    list1.addAtTail(4);
    list1.addAtTail(5);
    list1.addAtTail(6);

    list1.reverseList();


//    list2.addAtHead(5);
//    list2.addAtHead(1);
//
//     list1.PrintLots(list1.getHead(),list2.getHead());
////    list1.swap(list1.getHead(), nullptr);
//     list1.swap(list1.getHead());
     list1.displayAll();



//    list1.displayAll();

//    list1.deleteNode(8);

//    list1.displayAll();

    return 0;
}
