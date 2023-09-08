#include<iostream>
#include<vector>
using namespace std;


// here we use the binary search algorithm to find the first and last occurrence of the key;

/*  Binary Search
The main intuition behind this approach is that ‘ARR’ is already sorted. So, we will modify the binary search algorithm 
and find the first occurrence and last occurrence of ‘K’ in ‘ARR’.

 

Here is the algorithm:

We initialise two integer variables ‘first’ and ‘last’ to -1. They store the first and last occurrence of ‘K’, respectively.

We initialise two integer variables ‘start’ and ‘end’ denoting the start index and the end index to 0 and N -1, respectively. 

The modified binary search to find the first occurrence of ‘K’ :

We find the index of the middle element of ARR as mid = start + (end - start) /2 .
If (ARR[mid] == K)
first = mid
We update the end index, end = mid - 1.
Else If (ARR[mid] < K)
We update the start index, start = mid + 1. 
Else
We update the end index, end = mid - 1.
 

The modified binary search to find the last occurrence of ‘K’ :

We find the index of the middle element of ARR as mid = si + (ei - si) / 2
If (ARR[mid] == K)
last = mid
We update the start index, start = mid + 1.
Else If (ARR[mid] < K)
We update the start index, start = mid + 1.
Else If (ARR[mid] > K)
We update the end index, end = mid - 1.
   

Time Complexity
O(log(N)), where N is the length of the given array/list ARR. 

 

In binary search we are always dividing the search interval in half. Hence, the time complexity is O(log(N)).

Space Complexity
O(1), i.e. constant space complexity. */

void firstAndLastPair(vector <int> arr , int n , int k){
         // Write your code here
    int start = 0;
    int end = n-1;
    int middle = start + (end-start)/2;
   
    int firstPair = -1;
    int secondPair = -1;

    while(start<=end){
        if(arr[middle] == k){
            firstPair = middle;
            end = middle-1;
        }else if(arr[middle] > k){
            end = middle - 1;
        }else{
            start = middle+1;
        }
        middle = start + (end-start)/2;

    }
    start = 0;
    end = n-1;
    middle = start + (end-start)/2;

    while(start<=end){
        if(arr[middle] == k){
            secondPair = middle;
            start = middle+1;
        }else if(arr[middle] > k){
            end = middle - 1;
        }else{
            start = middle+1;
        }
        middle = start + (end-start)/2;

    }

    cout << endl << "The first occurence is: " << firstPair << " and the last occurence is: "<<secondPair;
}

int main(){
    vector <int> arr = {0,0,1,1,2,2,2,2};
    int n= arr.size();
    int k=2;

    firstAndLastPair(arr, n , k);
    return 0;
}