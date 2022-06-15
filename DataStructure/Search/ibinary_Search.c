#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 15

void print(int A[])
{
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void insertionSort(int A[])
{
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
    }

    for(int j = 0; j < N; j++)
    {
        printf("%d ", A[j]);
    }
    printf("\n");
}

int count;

int iBinarySearch(int A[], int key)
{
    int low = 0, high = N-1, middle;

    while(low <= high)
    {
        count++;
        int middle = (low + high) / 2;

        if(key == A[middle])
            return middle;
        else if(key < A[middle])
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}

int main()
{
    int A[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        A[i] = rand() % 100;
    }
    print(A); insertionSort(A);

    int key, idx;
    printf("Search Key : ");
    scanf("%d", &key);
    idx = iBinarySearch(A, key);

    if(idx == -1)
        printf("%d is not in A[]\n", key);
    else
        printf("%d Times : %d is in A[%d]\n", count, key, idx);


    return 0;
}