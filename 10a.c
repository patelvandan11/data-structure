


// ●Write a program to implement binary search
// binary search 0(log n)
// liner search 0(n)

#include <stdio.h>

// int linearsearch(int arr[], int size, int element)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == element)
//         {
//             return i;
//         }
//     }
//     return -1;
// }
int binarysearch(int arr[], int size, int element)
{
    int low, mid, high;
    // start
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // end
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 56, 466, 9746, 5512};
    int size = sizeof(arr) / sizeof(int);
    int element = 9746;
    int seachindex = binarysearch(arr, size, element);
    printf("the elements %d was found index %d \n", element, seachindex);

    return 0;
}