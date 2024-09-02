/*
Algorithm Quicksort

QuickSort(arr,low,high)
{
    if(low<high)
    {
        j=partition(arr,low,high)
        QuickSort(arr,low,j-1)
        QuickSort(arr,j+1,high)
    }
}

partition(arr,low,high)
{
    i=low
    j=high
    X=arr[low]
    do
    {
        do
        {
            i++
        }while(a[i]<X)
        do
        {
            j--
        }while(a[j]>X)
        if(i<j)
            swap(arr[i],arr[j])
    }while(low<high)
    swap(X,arr[j])
    return j
}
*/
#include<stdlib.h>
#include<stdio.h>

void printarray(int *data,int N);
void QuickSort(int *data,int low,int high);
int partition(int *data,int low,int high);
void swap(int *arr1,int *arr2);

int main(void)
{
    int N;

    printf("\nEnter the size of the array:\n");
    scanf("%d",&N);

    int *data=(int *)malloc(N * sizeof(int));
    printf("\nEnter the elements of the data:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&data[i]);
    }

    printf("\nGiven array is:\n");
    printarray(data,N);
    
    QuickSort(data,0,N-1);

    printf("\nSorted array is:\n");
    printarray(data,N);

    free(data);
    
    return 0;
}


void printarray(int *data,int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d, ",data[i]);
    }
    printf("\n");
}

void QuickSort(int *data,int low,int high)
{
    if (low<high)
    {
        int j=partition(data,low,high);
        QuickSort(data,low,j-1);
        QuickSort(data,j+1,high);
    }
}

int partition(int *data,int low,int high)
{
    int i=low,j=high,X=data[low];

    do
    {
        do
        {
            i++;
        } while (data[i]<X);
        do
        {
            j--;
        } while (data[j]>X);
        if(i<j)
        {
            swap(&data[i],&data[j]);
        }
    } while (i<j);

    swap(&data[low],&data[j]);

    return j;
}

void swap(int *arr1,int *arr2)
{
    *arr1=*arr1 ^ *arr2 ^ (*arr2 = *arr1);
}