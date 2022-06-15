#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

void insertionSort(int A[])
{
    printf("Before Sort : ");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("<<<<<<<<<< Insertion Sorting >>>>>>>>>>\n");

    for(int i = 1; i <= N-1; i++)
    {
        int key = A[i];
        int j = i - 1;

        while(j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key; //right shift

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

    insertionSort(A);
    return 0;
}