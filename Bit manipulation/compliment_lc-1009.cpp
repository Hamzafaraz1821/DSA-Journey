// leetcode problem 1009;;

#include<iostream>
#include<math.h>
using namespace std;

void myApproach(){

    // in this approach invert every bit and for storing we use pow of 2s; as to convert the binary to decimal


        int n;
        n = 10;
        int ans=0;
        int i=0;
        if(n==0){
            cout  << endl << "The number is 0";
            return;
        }
        while(n!=0){
            int bit = n&1;
            if(bit==1){
                bit = 0;
            }else{
                bit = 1;
            }
            ans = (pow(2,i) * bit) +ans;
            n = n>>1;
            i++;
        }
        
        cout << endl << "The Complemented Decimal number is: "<< ans;
}

void effApproach(){
  
        // this is an efficient approach where we use a mask and negation of (n) to solve the problem
        // here we have done a good use of bit manipulation using the right shift, left shift, negation and (and) operator

        // let we have n=5; binary is = 101
        // when we negate a 5 we get  29(1s)010
        // we need a mask which contains 29(0s)111; 3 ones because we have 3 bits in 5;

        // when we & both the numbers we 1&0=0; 1&1=1;
         


        int n;
        n=5;
        int m=n;
        int mask=0;
        if(m==0){
            cout <<endl << "The number is 0";
            return;
        }
        while(m!=0){
            mask = (mask<<1) | 1;
            m = m>>1;
        }
        
        int ans = (~n)&mask;

        cout << endl << "The efficient approach complemented Number: "<< ans;

        


}

int main(){

    myApproach();
    effApproach();
    return 0;
}