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

void insertionSort(int arr[],int size){
    for(int i=1; i<size; i++){

        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }else{
                break;
            }
            display(arr);
        }
    }
}



int main(){

    int arr[SIZE] = {3,50,40,1,3};


    display(arr);

    insertionSort(arr, SIZE);

    display(arr);
}

