#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

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




int main() {
    bool exit = false;
    while (!exit) {
        cout << endl << "Enter the size of the array: ";
        int size;
        cin >> size;
        int arr[size];
        cout << endl << "Enter the elements of the array: ";
        for (int i = 0; i < size; i++) {
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

        // Declare time points and duration variables
        high_resolution_clock::time_point start, stop;
        duration<double, std::milli> ms_double;

        switch (choice) {
            case 1:

                // before sorting
                cout << "Before sorting: " << endl;
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;

                // Get the start time point
                start = high_resolution_clock::now();

                selectionSort(arr, size);

                // Get the stop time point
                stop = high_resolution_clock::now();

                // Calculate the duration in milliseconds
                ms_double = stop - start;

                // after sorting
                cout << "After sorting: " << endl;
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }

                // Print the execution time
                cout << "\nTime taken by function: " << ms_double.count() << "ms\n";

                break;
            case 2:
                // before sorting
                cout << "Before sorting: " << endl;
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;

                // Get the start time point
                start = high_resolution_clock::now();

                bubbleSort(arr, size);

                // Get the stop time point
                stop = high_resolution_clock::now();

                // Calculate the duration in milliseconds
                ms_double = stop - start;

                // after sorting
                cout << "After sorting: " << endl;
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }

                // Print the execution time
                cout << "\nTime taken by function: " << ms_double.count() << "ms\n";
                break;

                case 3:
                // Get the start time point
                start = high_resolution_clock::now();

                insertionSort(arr, size);

                // Get the stop time point
                stop = high_resolution_clock::now();

                // Calculate the duration in milliseconds
                ms_double = stop - start;

                //after sorting
                cout << "After sorting: " << endl;
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }

                // Print the execution time
                cout << "\nTime taken by function: " << ms_double.count() << "ms\n";

                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
