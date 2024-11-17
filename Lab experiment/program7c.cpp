/**
 * 
 * Write a program to sort the given elements with the sorting techniques given below
 * 
 * (c) Heap sort
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
using namespace std;


void heapify(int *arr, int n, int i);
void heapSort(int *arr, int n);
void printArray(int *arr, int n);

int main() {
    int n;

    cout << "Enter the size of the array:\n";
    cin >> n;

    int *arr = new int[n]; 
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nGiven array is:\n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "\nSorted array is:\n";
    printArray(arr, n);

    delete[] arr; 
    return 0;
}

// Function to build a max heap
void heapify(int *arr, int n, int i) {
    int largest = i;        
    int left = 2 * i + 1;   
    int right = 2 * i + 2;  

    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    
    if (largest != i) 
    {
        swap(arr[i], arr[largest]); 

        
        heapify(arr, n, largest);
    }
}


void heapSort(int *arr, int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

   
    for (int i = n - 1; i > 0; i--) {
      
        swap(arr[0], arr[i]);

       
        heapify(arr, i, 0);
    }
}


void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
