#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

void swap(int A[], int i, int min)
{
    int temp = A[min];
    A[min] = A[i];
    A[i] = temp;
}

void selectionSort(int A[])
{
    printf("Before Sort : ");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("<<<<<<<<<< Seleciton Sorting >>>>>>>>>>\n");

    for(int i = 0; i <= N-2; i++)
    {
        int min = i;
        for(int j = i+1; j <= N-1; j++)
            if(A[j] < A[min])
                min = j;

        swap(A, i, min);

        printf("%d Pass -> ", i+1); //step check
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

    selectionSort(A);
    return 0;
}