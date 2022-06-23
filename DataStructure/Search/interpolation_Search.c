#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 15   //DATA TABLE

void print(int A[])
{
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void insertionSort(int A[])
{
    for(int i = 1; i < N; i++)
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
    print(A);
}

int interpolationSearch(int A[], int key)
{
    int low = 0, high = N - 1;

    while(A[low] <= key && key <= A[high])
    {
        int i = ((float)(key - A[low]) / (A[high] - A[low]) * (high - low) + low);
        printf("%d\n", i);

        if(key == A[i])
            return i;
        else if(key < A[i])
            high = i - 1;
        else
            low = i + 1;
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
    idx = interpolationSearch(A, key);

    if(idx == -1)
        printf("%d is not in A[]\n", key);
    else
        printf("%d is in A[%d]\n", key, idx);

    return 0;
}