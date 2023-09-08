// search element in an array by using binary search algorithm 

#include<iostream>
using namespace std;

int binarySearch(int arr[], int key, int );

int main(){
    int arr[5] = {3,5,9,13,27};
    int key = 13;

    int index = binarySearch(arr,key,5);
    if(index == -1){
        cout << endl << "Number not found";
    }else{
        cout << endl << "The index of the key is: "<< index;
    }

    return 0;
}

int binarySearch(int arr[], int key, int length){


    int start = 0;
    int end = length-1;
    int mid = start + (end - start)/2;

    // we can find mid by mid = (start+end)/2; but we want to optimize it because if we get start+end > INT_MAX we will get an error

    // so we use mid = s + (e-s)/2

    while(start<end){
        if(arr[mid] > key){
            end = mid-1;
        }else if(arr[mid] < key){
            start = mid+1;
        }else{
            return mid;
        }
        mid = start + (end - start)/2;
        
    }
    return -1;
}