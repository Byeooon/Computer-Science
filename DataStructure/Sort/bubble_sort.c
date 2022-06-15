#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10
#define FALSE 0
#define TRUE 1

void swap(int A[], int j)
{
    int temp = A[j-1];
    A[j-1] = A[j];
    A[j] = temp;
}

void bubbleSort(int A[])
{
    printf("Before Sort : ");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("<<<<<<<<<< Bubble Sorting >>>>>>>>>>\n");

    for(int i = 1; i <= N-1; i++)
    {
        int flag = FALSE;
        for(int j = 1; j <= N-i; j++)
        {
            if(A[j-1] > A[j])
            {
                swap(A, j);
                flag = TRUE;
            }
        }

        if(flag == FALSE) //Avoid Duplicate Processing
            break;

        printf("%d Pass -> ", i); //step check
        for(int i = 0; i < N; i++)
            printf("%d ", A[i]);
        printf("\n");
    }
}

int main()
{
    int A[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
        A[i] = rand() % 100;

    bubbleSort(A);
    return 0;
}