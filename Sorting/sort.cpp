//
// Created by hamza on 16/10/2023.
//

#include<iostream>
#include<chrono>
using namespace std;

void selectionSort(int* arr, int size){
    int i, j, minIndex, temp;

    for(i = 0; i < size - 1; i++){
        minIndex = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

}

void bubbleSort(int* arr, int size){
    int i, j, temp;
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

}

void insertionSort(int* arr, int size){
    int i, j, key;
    for(i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}




int main(){
    bool exit = false;
    while(!exit){
        cout <<endl<< "Enter the size of the array: ";
        int size;
        cin >> size;
        int arr[size];
        cout <<endl<< "Enter the elements of the array: ";
        for(int i = 0; i < size; i++){
            cin >> arr[i];
        }
        cout << "Choose the sorting algorithm: " << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:

                // before sorting
                cout << "Before sorting: " << endl;
                for(int i=0; i<size; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
                selectionSort(arr, size);

                // after sorting
                cout << "After sorting: " << endl;
                for(int i=0; i<size; i++){
                    cout << arr[i] << " ";
                }
                break;
            case 2:
                // before sorting
                cout << "Before sorting: " << endl;
                for(int i=0; i<size; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
                bubbleSort(arr, size);

                // after sorting
                cout << "After sorting: " << endl;
                for(int i=0; i<size; i++){
                    cout << arr[i] << " ";
                }
                break;
            case 3:
                //before sorting
                cout<<"Before sorting: "<<endl;
                for(int i=0; i<size; i++){
                    cout << arr[i] << " ";
                }
                insertionSort(arr, size);

                //after sorting
                cout << "After sorting: " << endl;
                for(int i=0; i<size; i++){
                    cout << arr[i] << " ";
                }
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
