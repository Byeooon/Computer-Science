#include <stdlib.h>
#include <stdio.h>

typedef struct DListNode
{
    char data;
    struct DListNode* next;
    struct DListNode* prev;
}DListNode;

void init(DListNode* H, DListNode* T)
{
    H->next = T;
    T->prev = H;
}

void insert(DListNode* H, int pos, char e)
{
    DListNode* p = H;
    for(int i = 1; i <= pos -1; i++)
    {
        p = p->next;
    }
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node->data = e;
    node->next = p->next;
    p->next->prev = node;
    node->prev = p;
    p->next = node;
}

void delete(DListNode* H, int pos)
{
    DListNode* p = H;
    DListNode* q = H;
    for(int i = 1; i <= pos ; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    p->next->prev = q;
    printf("delete pos %d : %c \n", pos, p->data);
    free(p);

}


void print(DListNode* H,DListNode* T)
{
    DListNode* p = H;
    while (p->next != T)
    {
        p = p->next;
        printf("%c <-> ", p->data);
    }
    printf("\n");
}

int main()
{
    DListNode* H = (DListNode*)malloc(sizeof(DListNode));
    DListNode* T = (DListNode*)malloc(sizeof(DListNode));

    init(H, T);

    insert(H, 1, 'A'); print(H, T);
    insert(H, 2, 'B'); print(H, T);
    insert(H, 3, 'C'); print(H, T);
    insert(H, 2, 'D'); print(H, T);
    insert(H, 2, 'E'); print(H, T);

    delete(H, 2); print(H, T);
    delete(H, 3); print(H, T);

    return 0;
}