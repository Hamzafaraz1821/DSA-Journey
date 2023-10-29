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


void selectionSort(int arr[]){

    for(int i=0; i<SIZE-1; i++){
        int min_index = i;

        for(int j=i+1; j<SIZE; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        if(min_index != i){
            swap(arr[min_index],arr[i]);
        }
        display(arr);
    }
}

int main(){

    int arr[SIZE] = {9,4,7,1,3};

    display(arr);
    selectionSort(arr);

    display(arr);
}
