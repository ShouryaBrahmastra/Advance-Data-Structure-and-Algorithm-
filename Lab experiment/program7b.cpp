/**
 * 
 * Write a program to sort the given elements with the sorting techniques given below
 * 
 * (b) Quick sort
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
using namespace std;

void printarray(int *data, int N);
void QuickSort(int *data, int low, int high);
int partition(int *data, int low, int high);
void swap(int *a, int *b);

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

    QuickSort(data, 0, N - 1);

    cout << "\nSorted array is:\n";
    printarray(data, N);

    delete[] data;

    return 0;
}

void printarray(int *data, int N) 
{
    for (int i = 0; i < N; i++) 
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

void QuickSort(int *data, int low, int high) 
{
    if (low < high) {
        int j = partition(data, low, high);
        QuickSort(data, low, j - 1);
        QuickSort(data, j + 1, high);
    }
}

int partition(int *data, int low, int high) 
{
    int i = low + 1, j = high;
    int pivot = data[low]; 

    do 
    {
        while (i <= high && data[i] < pivot) 
        {
            i++;
        }
        while (j >= low && data[j] > pivot) 
        {
            j--;
        }
        if (i < j) 
        {
            swap(&data[i], &data[j]);
        }
    } while (i < j);

    swap(&data[low], &data[j]); 

    return j;
}

void swap(int *a, int *b) 
{
    *a = *a ^ *b ^ (*b = *a); 
}
