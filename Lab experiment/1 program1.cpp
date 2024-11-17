/**
 * 
 * Write a program to perform all basic data structure operations 
 * (Insertion, deletion, searching, sorting) over array.
 * 
 * Author: Shourya Gupta
 * Copyright: ShouryaBrahmastra
 * 
 * **/

#include <iostream>
#include <malloc.h>
using namespace std;

void insertElement(int *arr, int &n, int element, int position); 
void deleteElement(int *arr, int &n, int position); 
int searchElement(int *arr, int n, int element);
void sortArray(int *data, int N); 
void displayArray(int *arr, int n);


int main(void) 
{    
    int n = 0; // Current size of the array
    int N, choice, element, position;
    cout << "\nEnter the size of the array: ";
    cin >> N;
    int *arr = (int*)malloc(N * sizeof(int)); 

    while (true) 
    {
        cout << "Choose an operation:" << endl;
        cout << "1. Insert an element" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Search for an element" << endl;
        cout << "4. Sort the array" << endl;
        cout << "5. Display the array" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> element;
                cout << "Enter the position: ";
                cin >> position;
                insertElement(arr, n, element, position);
                break;
            case 2:
                cout << "Enter the position of the element to delete: ";
                cin >> position;
                deleteElement(arr, n, position);
                break;
            case 3:
                cout << "Enter the element to search: ";
                cin >> element;
                position = searchElement(arr, n, element);
                if (position != -1) 
                {
                    cout << "Element found at position: " << position << endl;
                } 
                else 
                {
                    cout << "Element not found!" << endl;
                }
                break;
            case 4:
                sortArray(arr, n);
                cout << "Array sorted." << endl;
                break;
            case 5:
                displayArray(arr, n);
                break;
            case 6:
                free(arr);
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

void insertElement(int *arr, int &n, int element, int position) 
{
    if (position > n || position < 0) 
    {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = n; i > position; i--) 
    {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    n++;
}


void deleteElement(int *arr, int &n, int position) 
{
    if (position >= n || position < 0) 
    {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = position; i < n - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }

    n--;
}

int searchElement(int *arr, int n, int element) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == element) 
        {
            return i;
        }
    }
    return -1; // Element not found
}

void sortArray(int *data, int N) 
{
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N-i-1; j++)
        {
            if (data[j] > data[j+1])
            {
                // Swap the elements
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void displayArray(int *arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}