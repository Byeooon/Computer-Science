#include <stdlib.h>
#include <stdio.h>

typedef struct DListNode
{
    char data;
    struct DListNode *prev,*next;
}DListNode;

typedef struct
{
    DListNode* H;
}Dlistype;

void init(Dlistype* DL)
{
    DL->H = NULL;
}

void insertFirst(Dlistype* DL, char e)
{
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    DListNode* p = DL->H;
    node->data = e;
    node->prev = NULL;
    node->next = p;
    DL->H = node;

    if(p != NULL)
        p->prev = node;
}

void insert(Dlistype* DL, int pos, char e)
{
    DListNode* p = DL->H;
    for(int i = 1; i < pos - 1; i++)
    {
       p = p->next;
    }
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node->data = e;
    node->next = p->next;
    node->next->prev = node;
    p->next = node;
    node->prev = p;

}
void print(Dlistype* DL)
{
    DListNode* p = DL->H;
    while (p != NULL)
    {
        printf("%c <-> ", p->data);
        p = p->next;   
    }
    printf("\n");
    
}

int main()
{
    Dlistype DL;
    init(&DL);

    insertFirst(&DL, 'A'); print(&DL);
    insertFirst(&DL, 'B'); print(&DL);
    insertFirst(&DL, 'C'); print(&DL);
    insertFirst(&DL, 'D'); print(&DL);
    
    insert(&DL, 2, 'O'); print(&DL);

    return 0;
}