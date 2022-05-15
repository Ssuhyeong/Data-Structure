#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 4

typedef char element;
typedef struct{
    element queue[Q_SIZE];
    int front, rear;
}QueueType;

QueueType *createQueue()
{
    QueueType *Q;
    Q = (QueueType*)malloc(sizeof(QueueType));
    Q -> front = -1;
    Q -> rear = -1;
    return Q;
}

int isEmpty(QueueType *Q)
{
    if(Q -> front == Q -> rear)
    {
        printf("\n\n Queue is Empty! \n");
        return 1;
    }
    else
        return 0;
}

int isFull(QueueType *Q)
{
    if(Q -> rear == Q_SIZE-1)
    {
        printf("\n\n Queue is Full \n");
        return 1;
    }
    else
        return 0;
}

void enQueue(QueueType *Q, element item)
{
    if(isFull(Q))
        return;
    else
    {
        Q -> rear++;
        Q -> queue[Q->rear] = item;
    }
}

element deQueue(QueueType *Q)
{
    if(isEmpty(Q))
        return 0;
    else
    {
        Q->front++;
        return Q->queue[Q -> front];
    }
}

element peek(QueueType *Q)
{
    if(isEmpty(Q))
        return 0;
    else
    {
        return Q -> queue[Q->front+1];
    }
}

void printQ(QueueType *Q)
{
    int i;
    printf("Queue: [ ");
    for(i = Q ->front+1;i <= Q->rear;i++)
        printf("%3c", Q ->queue[i]);
    printf("]");
}

int main(void)
{
    QueueType *Q1 = createQueue();
    element data;
    printf("\n 순차 큐 연산 \n");
    enQueue(Q1, 'A');
    enQueue(Q1, 'B');
    enQueue(Q1, 'C');
    printQ(Q1);
    data = peek(Q1);
    printf("\n %c \n", data);
    deQueue(Q1);
    deQueue(Q1);
    printQ(Q1);
    return 0;
    
}
