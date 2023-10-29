//
// Created by hamza on 16/10/2023.
//

#include<iostream>
#define SIZE 5
using namespace std;

void display(int arr[]){
    for(int i = 0; i < SIZE; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


void bubbleSort(int arr[],int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                display(arr);
            }
        }
    }
}

int main(){

    int arr[SIZE] = {9,4,7,1,3};

    display(arr);

    bubbleSort(arr, SIZE);

    display(arr);
}
