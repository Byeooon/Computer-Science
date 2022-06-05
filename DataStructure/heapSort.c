#include <stdlib.h>
#include <stdio.h>

#define N 100

typedef struct
{
    int heap[N];
    int heapSize;
}HeapType;

void init(HeapType* H)
{
    H->heapSize = 0;
}

void upHeap(HeapType* H)
{
    int i = H->heapSize;
    int key = H->heap[i];
    while ((i != 1) && (key > H->heap[i/2]))
    {
        H->heap[i] = H->heap[i/2]; //switch
        i /= 2;
    }
    H->heap[i] = key;
}

void downHeap(HeapType* H)
{
    int item = H->heap[1];
    int parent = 1, child = 2;

    while(child <= H->heapSize)
    {
        if((child < H->heapSize) && (H->heap[child+1] > H->heap[child]))
            child++;
        if(item >= H->heap[child])
            break;

        H->heap[parent] = H->heap[child];
        parent = child;
        child *= 2;
    }
    H->heap[parent] = item;
}

void insertItem(HeapType* H, int key)
{
    H->heapSize++;
    H->heap[H->heapSize] = key;
    upHeap(H);
}

int removeItem(HeapType* H)
{
    int item = H->heap[1]; //root Node
    H->heap[1] = H->heap[H->heapSize];
    H->heapSize--;
    downHeap(H);
    return item;
}

void heapSort_1(HeapType* H) //heapSort_1 -> assignment version
{
    int n = H->heapSize;
    int A[n];

    for(int i = n-1; i >= 0; i--)
        A[i] = removeItem(H);
    
    for(int i = 0; i < n; i++)
        printf("(%d) ", A[i]);
}

void heapSort_2(HeapType* H) //heapSort_2 -> replacement version
{
    int n = H->heapSize;

    for(int i = 1; i <= n; i++)
    {
        int key = removeItem(H);
        H->heap[H->heapSize + 1] = key;
    }
    for(int i = 1; i <=  n; i++)
        printf("(%d) ", H->heap[i]);
}

void printHeap(HeapType* H)
{
    for(int i = 1; i <= H->heapSize; i++)
        printf("(%d) ", H->heap[i]);
    printf("\n");
}

int main()
{
    HeapType H;
    init(&H);

    insertItem(&H, 9); insertItem(&H, 7); insertItem(&H, 6);
    insertItem(&H, 5); insertItem(&H, 4); insertItem(&H, 3);
    insertItem(&H, 2); insertItem(&H, 2); insertItem(&H, 1);
    insertItem(&H, 3); printHeap(&H); getchar();

    // heapSort_1(&H);

    heapSort_2(&H); 

    return 0;
}