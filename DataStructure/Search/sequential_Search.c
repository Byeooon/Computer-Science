#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 15

int sequentialSearch(int A[], int key, int low, int high)
{
    for(int i = low; i < high; i++)
    {
        if(A[i] == key)
            return i;
    }
    return -1;
}

void print(int A[])
{
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int A[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        A[i] = rand() % 100;
    }
    print(A);

    int key, idx;
    printf("Search Key : ");
    scanf("%d", &key);
    idx = sequentialSearch(A, key, 0, N-1);

    if(idx == -1)
        printf("%d is not in A[]\n", key);
    else
        printf("%d is in A[%d]\n", key, idx);

    return 0;
}