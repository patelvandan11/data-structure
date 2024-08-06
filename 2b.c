// ●Write a program to prints array elements in reverse orders applying pointers

#include <stdio.h>

void reverse(int *arr, int size)
{
    int *ptr = arr + size - 1;
    while (ptr >= arr)
    {
        printf("%d ,", *ptr);
        ptr--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    // printf("size :%d ", sizeof(arr[0]));

    reverse(arr, size);
    return 0;
}
