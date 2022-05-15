#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE];
int top = -1;

int isEmpty()
{
    if(top == -1)   return 1;
    else    return 0;
}

int isFull()
{
    if(top == STACK_SIZE-1) return 1;
    else return 0;
}

void push(element item)
{
    if(isFull())
    {
        printf("\n\nstack is FULL! \n");
        return;
    }
    
    else{
        stack[++top] = item;
    }
}

element pop()
{
    if(isEmpty())
    {
        printf("\n\nstack is Empty! \n");
        return 0;
    }
    else
    {
        return stack[top--];
    }
}

element peek()
{
    if(isEmpty())
    {
        printf("\n\nstack is Empty \n");
        exit(1);
    }
    else
        return stack[top];
}

void printStack()
{
    int i;
    printf("\n STACK [");
    for(i = 0;i<=top;i++)
        printf("%d", stack[i]);
    printf("]");
}

int main(void)
{
    element item;
    printf("\n** 순차 스택 연산 **\n");
    printStack();
    push(1);
    push(2);
    push(3);
    
    printStack();
    
    item = pop();
    printf("%d \n", item);
    item = pop();
    printf("%d \n", item);
    return 0;
}
