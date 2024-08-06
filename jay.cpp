#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Check if the queue is empty
int isEmpty()
{
    return (front == -1);
}

// Check if the queue is full
int isFull()
{
    return (rear == MAX_SIZE - 1);
}

// Enqueue (add) an element to the rear of the queue
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty())
    {
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

// Dequeue (remove) an element from the front of the queue
int dequeue()
{
    int value;
    if (isEmpty())
    {
        printf("Queue is empty\n");
        exit(1);
    }
    value = queue[front];
    if (front == rear)
    {
        // Last element in the queue
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return value;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    return 0;
}