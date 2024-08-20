/*
Selection sort Algorithm

    Selectionsort(data,N)
1.  for i<- 1 to N-1
2.      min j <- i
3.      min x <- data[i]
4.      for j <- i+1 to N
5.          if (data[j] < min x)
6.              min j <- j
7.              min x <- data[j]
8.      data[min j] <- data[i]
9.      data[i] <- min x
*/

#include<stdio.h>
#include<stdlib.h>

void printarray(int *arr,int N);
void selectionsort(int *arr,int N);
void swap(int *arr,int *arr1);

int main(void)
{
    int N;

    printf("\nSelection Sort\n");
    printf("Enter the size of the array:\n");
    scanf("%d",&N);

    printf("\nEnter the elements of the array:\n");
    int *arr=(int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("\nArray before sorting\n");
    printarray(arr,N);

    selectionsort(arr,N);

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

void selectionsort(int *arr,int N)
{
    for (int i = 0; i < N-1; i++)
    {
        int min=i;
        for (int j = i+1; j < N; j++)
        {
            if (arr[j]<arr[min])       
            {
                min=j;
            }
        }
        if(min != i)
        {
            swap(&arr[min],&arr[i]);
        }
    }
    
}

void swap(int *arr,int *arr1)
{
    int temp=*arr;
    *arr=*arr1;
    *arr1=temp;
}