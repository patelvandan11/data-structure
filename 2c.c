// Write program to implement stack and simple queue using array

// Write program to implement stack and simple queue using array 


#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int data)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = data;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = stack[top];
    top--;
    return data;
}

void display()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack are:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

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
}

void display_queue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue are:\n");
    for (int i = front; i <= rear; i++)
        printf("%d\n", queue[i]);
}

int main()
{
    // Stack operations
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped element: %d\n", pop());
    display();

    // Queue operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display_queue();
    printf("Dequeued element: %d\n", dequeue());

    return 0;
}