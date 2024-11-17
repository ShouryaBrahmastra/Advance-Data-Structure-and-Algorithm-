/**
 * 
 * Write a program to sort the given elements with the sorting techniques given below
 * 
 * (a) Merge Sort
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
#include <cstdlib>
using namespace std;

void mergesort(int *data, int low, int high);
void merge(int *data, int low, int mid, int high);
void printarray(int *data, int size);

int main() {
    int N;

    cout << "\nEnter the size of the array:\n";
    cin >> N;

    int *data = new int[N]; 
    cout << "\nEnter the elements of the array:\n";
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    cout << "\nGiven array is:\n";
    printarray(data, N);

    mergesort(data, 0, N - 1);

    cout << "\nSorted array is:\n";
    printarray(data, N);

    delete[] data; 
    return 0;
}

void printarray(int *data, int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void mergesort(int *data, int low, int high) {
    if (low < high) { 
        int mid = low + (high - low) / 2;
        mergesort(data, low, mid);
        mergesort(data, mid + 1, high);
        
        merge(data, low, mid, high);
    }
}

void merge(int *data, int low, int mid, int high) {
    int size = high - low + 1;
    int *temp = new int[size]; 
    int i = low, j = mid + 1, k = 0;

    
    while (i <= mid && j <= high) {
        if (data[i] <= data[j]) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    
    while (i <= mid) {
        temp[k++] = data[i++];
    }

    
    while (j <= high) {
        temp[k++] = data[j++];
    }

    
    for (int p = 0; p < size; p++) {
        data[low + p] = temp[p];
    }

    delete[] temp; 
}
