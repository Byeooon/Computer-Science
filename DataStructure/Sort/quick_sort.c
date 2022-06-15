//fix the leftmost side to pivot
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 15
//macro
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) =(t))

int partition(int list[], int left, int right)
{
    int pivot = list[left];
    int low = left;
    int high = right + 1;
    int temp;

    do
    {
        do
            low++;
        while(list[low] < pivot);

        do
            high--;
        while(list[high] > pivot);

        if(low < high)
            SWAP(list[low], list[high], temp);

    }while(low < high);

    SWAP(list[left], list[high], temp);
    return high;
}

void quickSort(int list[], int left, int right)
{
    if(left < right)
    {
        int p = partition(list, left, right);
        quickSort(list, left, p-1);
        quickSort(list, p+1, right);
    }
}

int main()
{
    int list[N];
    srand(time(NULL));

    for(int i = 0; i < N; i++)
        list[i] = rand() % 100;

    printf("Before Sorting : ");
    for(int i = 0; i < N; i++)
        printf("%d ", list[i]);
    printf("\n");

    quickSort(list, 0, N-1);

    getchar();

    printf("After Sorting : ");
    for(int i = 0; i < N; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}