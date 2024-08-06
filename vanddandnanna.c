//  radix sort algo 

#include <stdio.h>

int get_max_ele(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
    {
		if (arr[i] > max)
        {
			max = arr[i];
        }
    }
	return max;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	// output array
	int output[n];
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
    {
		count[(arr[i] / exp) % 10]++;
    }

	// Change count[i] so that count[i] now contains actual position of this digit in output[]
	for (i = 1; i < 10; i++)
    {
		count[i] += count[i - 1];
    }

	// Build the output array
	for (i = n - 1; i >= 0; i--) 
    {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
    {
		arr[i] = output[i];
    }
}

void radixsort(int arr[], int n)
{

	int m = get_max_ele(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
    {
		countSort(arr, n, exp);
    }
}

void print(int arr[], int n)
{

	for (int i = 0; i < n; i++)
    {
		printf("%d ", arr[i]);
    }
}

int main()
{
	int arr[] = { 405,202, 75, 1, 555, 600, 100, 1025 };
	int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before applying Radixsort : \n");
	print(arr, n);
    printf("\nAfter applying Radixsort : \n");
	radixsort(arr, n);
	print(arr, n);
	return 0;
}