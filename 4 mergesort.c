/*
Algorithm mergesort

Given an array of n elements a[1...n]
// array[low,high]

Algo Mergesort(low,high)
    //a[low,high] array of n elements
    if(low<high) //more than 1 element
        mid=(low+high)/2
        Mergesort(low,mid)
        Mergesort(mid+1,high)
    //conquer
    merge(low,mid,high)

Algo merge(low,mid,high)
i=low,j=mid+1, k=low
while(i<=mid && j<=high)
    if(a[i]<=a[j])
    { b[k]=a[i], i++}
    else
    { b[k]=a[j], j++}
    k++
if(i>mid)
for(p=j,p<=high,p++)
    { b[k]=a[p], k++}
else
for(p=i,p<=mid,p++)
    {   b[k]=a[p]}


//copy back
for(p=low,p<=high,p++)
    {   a[p]=b[p]}

*/

#include<stdlib.h>
#include<stdio.h>

void mergesort(int *data,int low,int high);
void merge(int *data,int low,int mid,int high);
void printarray(int *data,int N);

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
    
    mergesort(data,0,N-1);

    printf("\nSorted array is:\n");
    printarray(data,N);

    return 0;
}


void printarray(int *data,int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d, ",data[i]);
    }
    
}

void mergesort(int *data,int low,int high)
{
    if(low<high) //more than one element cos if = then one element no comparison
    {
        int mid=low+(high-low)/2;
        mergesort(data,low,mid);
        mergesort(data,mid+1,high);
        //conquer
        merge(data,low,mid,high);
    }
}

void merge(int *data,int low,int mid,int high)
{
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    int *data2=(int *)malloc((high-1) *sizeof(int));
    while (i<=mid && j<=high)       
    {
        if(data[i]<=data[j])
        {
            data2[k++]=data[i++];
        }
        else
        {
            data2[k++]=data[j++];
        }   
    }

    while (i<=mid)
    {
        data2[k++]=data[i++];
    }
    while (j<=high)
    {
        data2[k++]=data[j++];
    }
    

    for (int p = low; p < k; p++)
    {
        data[p]=data2[p];
    }
    
    
    
}