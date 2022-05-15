#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stackNode
{
    element data;
    struct stackNode *link;
}stackNode;

stackNode *top;

element isEmpty()
{
    if(top == NULL) return 1;
    else return 0;
}

void push(element item)
{
    stackNode *temp = (stackNode*)malloc(sizeof(stackNode));
    temp -> data = item;
    temp -> link  = top;
    top = temp;
}

element pop()
{
    element item;
    stackNode *temp = top;
    if(isEmpty())
    {
        printf("\n\n Stack is Empty! \n");
        return 0;
    }
    else
    {
        item = temp ->data;
        top = temp -> link;
        free(temp);
        return item;
    }
}

element peek()
{
    if(top == NULL)
    {
        printf("\n\n Stack is Empty! \n");
        return 0;
    }
    else
        return(top->data);
}

void printStack()
{
    stackNode *p = top;
    printf("\n Stack[");
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p -> link;
    }
    printf("]");
}

int main(void)
{
    element item;
    printf("\n 연결 스택 연산 \n");
    printStack();
    push(1);
    push(2);
    push(3);
    printStack();
    
    item = pop();
    printf("%d \n", item);
    printStack();
    return 0;
}
