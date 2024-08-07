//  Write a program to insert/delete in linear array at specific position.

#include <stdio.h>
int insert(int a[], int n)
{
    int pos, element;
    printf("At which index position you want to insert element:");
    scanf("%d", &pos);
    printf("Element:");
    scanf("%d", &element);

    for (int i = n + 1; i >= 0; i--)
    {
        if (i > pos)
        {
            a[i] = a[i - 1];
        }
    }
    a[pos] = element;
    for (int i = 0; i < n + 1; i++)
    {
        printf("a[%d]:%d\n", i, a[i]);
    }
    return 0;
}

int delet(int a[], int n)
{
    int pos;
    printf("Which index position you want to delete element:");
    scanf("%d", &pos);

    for (int i = 0; i < n - 1; i++)
    {
        if (i >= pos)
        {
            a[i] = a[i + 1];
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        printf("a[%d]:%d\n", i, a[i]);
    }
    return 0;
}

int search(int a[], int n)
{
    int element;
    printf("Which number you can search ?:");
    scanf("%d", &element);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == element)
        {
            printf("a[%d]:%d", i, a[i]);
        }
    }
}

int main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);
    
    int a[n];

    for (int i = 0; i < n; i++)
    {
        printf("a[%d]:", i);
        scanf("%d", &a[i]);
    }
    printf("Displaying array that you have entered\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("a[%d]:%d\n", i, a[i]);
    }

    int choice;

    printf("Enter your choice wether insert(1)/delet(2)/search(3)\n");
    printf("Choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        insert(a, n);
        break;

    case 2:
        delet(a, n);
        break;

    case 3:
        search(a, n);
        break;

    default:
        printf("Invalid choice");
        break;
    }

    return 0;
}