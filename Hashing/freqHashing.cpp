//
// Created by hamza on 27/11/2023.
//

#include<iostream>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int size;
    cin >> size;
    int arr[size];

    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    int hash[12]{0};

    for(int i=0; i<5; i++){
        hash[arr[i]]++;
    }
    int q;
    cin>>q;

    while(q>0){
        int number;
        cin >> number;

        // fetching
        cout << "Freq of: " << number << " is: " << hash[number] << endl;
        q--;
    }
}
