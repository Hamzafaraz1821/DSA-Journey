// this solution gives correct answer until the pow function gives correct answer;

#include<iostream>
#include<math.h>
using namespace std;



// we can also use the mathimatical approach of it
void mathematicalMethod(){
    //take a number in decimal 
    int decimal = 10;
    int ans =0 ,i=0;

    while(decimal!=0){
        int bit = decimal % 2;
        ans = ans + (bit  * pow(10,i));

        decimal = decimal / 2;
        i++;
    }

    cout <<endl<< "The binary number by Mathematical Method " << ans;
}

void bitMethod(){

    // take a number in decimal
    int number = 10;
    int ans = 0,i=0;

    // applying bit manipulation

    while(number != 0){
        int bit = number&1;
        
        ans = (pow(10,i) * bit) + ans;

        // right shift the number by 1;
        number = number >> 1;
        i++;
    }

    cout <<endl<< "The number in bits by Bit Method " << ans;
}

int main(){

    // mathematical method 

    mathematicalMethod();

    // bit method

    bitMethod();
    
    return 0;
}