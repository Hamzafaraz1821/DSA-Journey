//
// Created by hamza on 30/10/2023.
//

#include<iostream>
using namespace std;

class twoStacks{
private:
    int* arr;
    int size;
    int top1;
    int top2;

public:
    twoStacks(int n){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x){
        if(top1<top2-1){
            top1++;
            arr[top1] = x;
        }else{
            cout << endl << "Stack overflow";
            exit(1);
        }
    }

    void push2(int x){
        if(top2-1>top1){
            top2--;
            arr[top2] = x;
        }else{
            cout << endl << "Stack overflow";
            exit(1);
        }
    }

    int pop1(){
        if(top1>=0){
            int x = arr[top1];
            top1--;
            return x;
        }else{
            cout << endl << "Underflow";
            exit(1);
        }
    }

    int pop2(){
        if(top2<size){
            int x = arr[top2];
            top2++;
            return x;
        }else{
            cout << endl << "Underflow";
            exit(1);
        }
    }
};

int main(){
    twoStacks stac(5);

    stac.push1(5);
    stac.push1(4);
    stac.push1(3);
    stac.push2(2);
    stac.push2(1);

    cout <<endl << "The poped value of stack1 is " << stac.pop1();
    cout <<endl << "The poped value of stack2 is " << stac.pop2();
    return 0;
}