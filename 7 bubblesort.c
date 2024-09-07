/*
Algorithm Quicksort

here data is an array having size N
Bubblesort(data,N)
1.  for i<-1 to N
2.      for j<-1 to N-i
3.          if(data[j]>data[j+1])
4.              swap(data[j],data[j+1])

*/
#include<stdio.h>
#include<stdlib.h>

void printarray(int *data, int N);
void Bubblesort(int *data, int N);

int main()
{
    int N;

    printf("\nEnter the size of the array:\n");
    scanf("%d", &N);

    int *data = (int *)malloc(N * sizeof(int));
    if (data == NULL) {
        printf("Memory not allocated.\n");
        return -1;
    }

    printf("\nEnter the elements of the array:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("\nGiven array is:\n");
    printarray(data, N);

    Bubblesort(data, N);

    printf("\nSorted array is:\n");
    printarray(data, N);

    free(data);

    return 0;
}

void printarray(int *data, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", data[i]);
    }
    printf("\n");
}

void Bubblesort(int *data, int N)
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
