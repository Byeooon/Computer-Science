#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
    char data;
    struct ListNode* next;
}ListNode;

typedef struct
{
    ListNode* H;
}ListType;

void init(ListType* L)
{
    L->H = NULL;
}

void insertFirst(ListType* L, char e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->next = L->H;
    L->H = node;
}

void insertLast(ListType* L, char e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = L->H;

    node->data = e;
    node->next = NULL;
    
    while (p->next != NULL)
        p = p->next;

    p->next = node;
    node->next = NULL;
}
void insert(ListType* L, int pos, int e)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* p = L->H;
    if(pos == 1)
        insertFirst(L,e);

    for(int i = 1; i < pos -1 ; i++)
        p = p->next;
    
    node->data = e;
    node->next = p->next;
    p->next = node;   
}

void deletFirst(ListType* L)
{
    ListNode* p = L->H;
    L->H = p->next;
    printf("delete first : %c\n", p->data);
    free(p);
}

void deleteLast(ListType* L)
{
    ListNode* p = L->H;
    ListNode* q = L->H;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    printf("delete last : %c\n", p->data);
    free(p);
}

void delete(ListType* L, int pos)
{
    ListNode* p = L->H;
    ListNode* q = L->H;
    for(int i = 1; i < pos ; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    printf("delete pos %d : %c \n", pos, p->data);
    free(p);
}

void print(ListType *L)
{
    ListNode* p;
    p = L->H;
    while(p != NULL)
    {
        printf("%c -> ", p->data);
        p = p->next;
    }
    printf("\n");

}

int main()
{
    ListType L;
    init(&L);

    insertFirst(&L, 'A'); print(&L);
    insertFirst(&L, 'B'); print(&L);
    insertFirst(&L, 'C'); print(&L);

    insertLast(&L, 'C'); print(&L);
    insertLast(&L, 'D'); print(&L);

    printf("\n");

    insert(&L, 3,'E'); print(&L);

    deletFirst(&L); print(&L);
    deleteLast(&L); print(&L);
    delete(&L, 2); print(&L);

    return 0;
}