//
// Created by hamza on 27/11/2023.
//
#include<iostream>
#include<map>
using namespace std;


int main(){
    int arr[5]{3,2,3,5,5};

    map<int,int> mpp;

    for(int i : arr){
        mpp[i]++;
    }

    for(auto it:mpp){
        cout << it.first << " and freq " << it.second <<endl;
    }

//    int q;
//    cin >> q;
//    while(q>0){
//        int number;
//        cin >> number;
//
//        // fetching
//
//        cout << mpp[number];
//    }

}