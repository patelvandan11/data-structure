// Write a program for queue using array for the following operations: Enqueue, Dequeue, IsEmpty, IsFull.



#include <stdio.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = data;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue[front];
    front++;
    return data;
    
    printf("dequeue %d from the queue",queue[front]);
}

void display_queue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    // printf("Elements in the queue are:\n");
    for (int i = front; i <= rear; i++)
        printf("enqueue %d from the queue  \n", queue[i]);
}
int  main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display_queue();
    printf("Dequeued element: %d\n", dequeue());

    return 0;
}