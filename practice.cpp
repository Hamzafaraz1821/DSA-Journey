#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    cout << "Enter your option: " << endl;
    int n;
    try {

//        if (n < 0) {
//            // If a negative number is entered, throw a standard exception
//            throw invalid_argument("Negative number entered.");
//        }
        if(cin>>n){
            cout << "You entered: " << n << endl;
        }else{
            throw invalid_argument("Invalid input.");
        }

        // Code that may throw an exception

    } catch (const exception& e) {
        // Handle the standard exception and retrieve the error message
        cerr << "Standard Exception caught: " << e.what() << endl;
    }

    return 0;
}
