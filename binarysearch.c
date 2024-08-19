/**
Advance Data Structure and Algorithm 

Binary search

  BinarySearch(data,low,high,item,loc)
1. while(low<=high)
2.    mid=(low+high)/2
3.    if(data[mid]>item)
4.           high=mid-1
5.    if(data[mid]<item)
6.           low=mid+1
7.    else
8.           loc=mid
9.           return
10. loc=-1 & return
**/
#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *data,int low,int high,int item)
{
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (item == data[mid])
        {
            /* code */
            return mid;
        }
        else if (item < data[mid])
        {
            /* code */
            high = mid - 1;
        }
        else if (item > data[mid])
        {
            low = mid + 1;
        }
    }
    return -1;  
}

int main(void)
{
    int item, N;
    printf("Enter the size of the array\n");
    scanf("%d", &N);

    int *data = (int *)malloc(N * sizeof(int));

    printf("Enter the data elements:\n");
    for (int i = 0; i < N; i++)
    {
        /* code */
        scanf("%d", &data[i]);
    }
    printf("\nEnter the item to be searched for\n");
    scanf("%d", &item);

    int result=binarysearch(data, 0, N-1, item);

    if (result==-1)
    {
        printf("\nElement %d is not present in the array\n",item);
    }
    else
    {
        printf("\nThe element %d is found at index %d",item,result+1);
    }
    
    

    return 0;
}