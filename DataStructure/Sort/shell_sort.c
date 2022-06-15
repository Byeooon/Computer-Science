#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 15

void shellSort(int A[])
{
    printf("Before Sort : ");
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("<<<<<<<<<< Shell Sorting >>>>>>>>>>\n");

    for(int gap = 5; gap >= 1; gap -= 2)
    {
        for(int i = gap; i <= N-1; i++)
        {
            int key = A[i];
            int j = i;

            while(j >= gap && A[j - gap] > key)
            {
                A[j] = A[j - gap];
                j -= gap;
            }
            A[j] = key;
        }

        printf(" Gap %d -> ", gap); //Gap check
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

    shellSort(A);
    return 0;
}