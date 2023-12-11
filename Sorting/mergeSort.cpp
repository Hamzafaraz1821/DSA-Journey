//
// Created by hamza on 20/11/2023.
//

#include<iostream>
#include<vector>
#include<chrono>
using namespace std;

// mergeSort using vectors

void mergeSort(vector<int>& arr,int start,int end){

    if(start<end) {
        int size = arr.size();
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        int i = start;
        int j = mid + 1;
        int k = start;

        vector<int> temp(size);

        while (i <= mid && j <= end) {
            if (arr[i] < arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }

        while (j <= end) {
            temp[k] = arr[j];
            j++;
            k++;
        }

        for (int i = start; i <= end; i++) {
            arr[i] = temp[i];
        }
    }

}


//class doublyLinked{
//    struct Node{
//        int data;
//        Node* next;
//        Node* prev;
//    };
//    Node* headPtr;
//    Node* tailPtr;
//
//public:
//    Node* getHead(){
//        return headPtr;
//    }
//    void addNodeAtHead(int);
//    Node* swap(Node* );
//    void displayAll();
//    void mergeSort();
//};
//
//doublyLinked::Node* doublyLinked::swap(Node* head){
//    if(head == nullptr || (head->next == nullptr && head->prev != nullptr)){
//        return head;
//    }
//
//    Node* first = head;
//    Node* second = head->next;
//    Node* third = second->next;
//
//    if(head == headPtr){
//        second->prev = nullptr;
//        headPtr = second;
//    }
//
//    second->next = first;
//    first->prev = second;
//    first->next = swap(third);
//
//    return second;
//}
//
//void doublyLinked::addNodeAtHead(int value) {
//    Node* newNode = new Node;
//
//    if(headPtr == nullptr){
//        tailPtr = newNode;
//
//        newNode->data = value;
//        newNode->next = headPtr;
//        newNode->prev = headPtr;
//    }else {
//        newNode->data = value;
//        newNode->next = headPtr;
//        newNode->prev = nullptr;
//        headPtr->prev = newNode;
//    }
//
//    headPtr = newNode;
//}
//
//void doublyLinked::mergeSort() {
//
//}
//
//void doublyLinked::displayAll(){
//    Node* temp = headPtr;
//    while(temp!= nullptr){
//        cout << "->" << temp->data;
//        temp = temp->next;
//    }
//}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1,7,9,6,0,8,10};

    // get the start time
    auto start = chrono::high_resolution_clock::now();

    mergeSort(arr, 0, arr.size()-1);

    // get the end time
    auto end = chrono::high_resolution_clock::now();

    // calculate and print the duration in milliseconds
    auto duration = chrono::duration_cast<chrono::nanoseconds >(end - start);
    cout << "Time taken by mergeSort: " << duration.count() << " nanoseconds" << endl;

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

#include<iostream>
using namespace std;

int main(){
    return 0;
}
