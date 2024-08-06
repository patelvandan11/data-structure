//  quick sort algorithem 

#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition
    if (low < high)
    {
       
        partitionIndex = partition(A, low, high); 
        printf("partitions :\n");
        printArray(A,7);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int A[] = {9, 4, 2, 8, 7, 5, 6};
    int n = 7;
    // n =7;

    printf("Before applying a Quick sort  Array is:\n");
    printArray(A, n);
    printf("Start Quicksort Algo :\n");
    quickSort(A, 0, n - 1);
    printf("After applying a Quick sort Final Output:\n");
    printArray(A, n);
    return 0;
}
