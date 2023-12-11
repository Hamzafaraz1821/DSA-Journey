//
// Created by hamza on 20/11/2023.
#include<iostream>
#include<vector>
using namespace std;

// mergeSort using vectors and pointers

void mergeSort(vector<int>& arr,int start,int end){

    if(start<end) {
        int size = arr.size();
        int mid = (start + end) / 3;
        mergeSort(arr, start, mid);
        mergeSort(arr,mid+1,mid+mid);
        mergeSort(arr, mid + mid + 1, end);
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

int main(){
    vector<int> arr = {5,4,3,2,1};
    mergeSort(arr,0,4);
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
}
