/**
    Insertionsort(data,N)
1.  for j<-2 to N
2.      key=data[j]
3.      i=j-1
4.      while i>0 && key<data[i]
5.          data[i+1]=data[i]
6.          i=i-1
7.      data[i+1]=key

**/

#include<stdlib.h>
#include<stdio.h>

void printarray(int *arr,int N);
void insertionsort(int *arr,int N);

int main(void)
{
    int N;

    printf("\nInsertion sort\n");
    printf("Enter the size of the array:\n");
    scanf("%d",&N);

    printf("\nEnter the elements of the array\n");
    int *arr=(int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nArray before sorting\n");
    printarray(arr,N);

    insertionsort(arr,N);

    printf("\nArray after sorting\n");
    printarray(arr,N);
    
    return 0;
}

void printarray(int *arr,int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d, ",arr[i]);
    }
}

void insertionsort(int *arr,int N)
{
    for (int j = 1; j < N; j++)
    {
        int key=arr[j];
        int i=j-1;
        while (i>=0 && key<arr[i])
        {
            arr[i+1]=arr[i];
            i=i-1;
        }
        arr[i+1]=key;
    }
    
}