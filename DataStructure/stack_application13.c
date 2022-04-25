#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct
{
    char data[SIZE];
    int top;

}StackType;

void init(StackType* S)
{
    S->top = -1;
}

int isEmpty(StackType* S)
{
    return S->top == -1;
}

int isFull(StackType* S)
{
    return S->top == SIZE - 1;
}

void push(StackType* S, char c)
{
    if(isFull(S))
        printf("Overflow!\n");
    else
    {
        S->top++;
        S->data[S->top] = c;
    }
}

char pop(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Empty!\n");
        return -1;
    }

    char c = S->data[S->top];
    S->top--;

    return c;
}

char peek(StackType* S)
{
    if(isEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }

    return S->data[S->top];

}

void print(StackType* S)
{
    for(int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);

    printf("\n");    
}

int main()
{
    StackType S;
    init(&S);

    char str[100];
	scanf("%s", str);
    StackType S1;
    StackType S2;
	init(&S1);
    init(&S2);

	int length = strlen(str);
    for(int i = 0; i < length; i++)
    {
        push(&S1, str[i]); //stack1 push
    }

	char tmp = pop(&S1); 
    push(&S2, tmp); 
    for(int i = 0; i < length - 1; i++)
    {
        if(tmp == peek(&S1)){
            pop(&S1);
        }
        else{
            tmp = pop(&S1);
            push(&S2, tmp);
        }
    }

    while(isEmpty(&S2) != 1 ) //비어있지 않을 동안
    {
        printf("%c",pop(&S2));
    }
	printf("\n");

    return 0;
} 