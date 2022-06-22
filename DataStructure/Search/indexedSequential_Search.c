#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N1 15   //DATA TABLE
#define N2 5    //INDEX TABLE

typedef struct 
{
    int key;
    int index;
}IndexTable;

int sequentialSearch(int A[], int key, int low, int high)
{
    for(int i = low; i < high; i++)
        if(A[i] == key)
            return i;
    
    return -1;
}

void print1(int A[])
{
    for(int i = 0; i < N1; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void print2(IndexTable IT[])
{
    for(int i = 0; i < N1/N2; i++)
        printf("[%2d : %2d]\n", IT[i].key, IT[i].index);
}

void makeIndexTable(int A[], IndexTable IT[])
{
    for(int i = 0, j = 0; i < N1/N2; i++, j += N2)
    {
        IT[i].key = A[j];
        IT[i].index = j;
    }
    print2(IT);
}

void insertionSort(int A[])
{
    for(int i = 1; i < N1; i++)
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
    print1(A);
}

int indexSearch(int A[], IndexTable IT[], int key)
{
    int i, low, high;

    for(i = 0; i < N1/N2; i++)
        if(IT[i].key <= key && IT[i+1].key > key)
            break;
    
    if(i == N1/N2 - 1)
    {
        low = IT[i].index;
        high = N1;
    }
    else
    {
        low = IT[i].index;
        high = IT[i+1].index;
    }
    printf("%d %d\n", low, high); 
    return sequentialSearch(A, key, low, high);
}

int main()
{
    int A[N1];
    IndexTable IT[N1/N2];

    srand(time(NULL));
    for(int i = 0; i < N1; i++)
    {
        A[i] = rand() % 100;
    }
    
    print1(A); insertionSort(A); makeIndexTable(A, IT);

    int key, idx;
    printf("Search Key : ");
    scanf("%d", &key);
    idx = indexSearch(A, IT, key);

    if(idx == -1)
        printf("%d is not in A[]\n", key);
    else
        printf("%d is in A[%d]\n", key, idx);

    return 0;
}