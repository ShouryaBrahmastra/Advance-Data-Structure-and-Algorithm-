/*
    Fact (N)
1.  if (N==0)
2.      return 1;
3.  else
4.      return Fact(N-1);
*/

#include<stdlib.h>
#include<stdio.h>

int fact(int N);

int main(void)
{
    int N;

    printf("\nFinding the Factorial\n");
    printf("Enter the number\n");
    scanf("%d",&N);

    if (N<0)
    {
        printf("\nFactorial not defined for negative numbers\n");
    }
    else 
    {
        int f=fact(N);
        printf("\nThe factorial of %d is %d",N,f);
    }

    return 0;
}

int fact(int N)
{
    if (N==0)
    {
        return 1;
    }
    else
    {
        return N * fact(N-1);
    }
}
