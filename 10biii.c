#include<stdio.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void selectionsort(int *A,int n)
{
    int temp;
    int indexofmin;
    for (int i = 0; i < n-1; i++)
    {
        indexofmin=i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j]<A[indexofmin])
            {
                indexofmin=j;
            }
            
        }
        temp=A[i];
        A[i]=A[indexofmin];
        A[indexofmin]=temp;
    }
    
}
int main()
{

    //  0     1      2       3        4
    //  |03    05    02       13      12

    // after first pass 
    //  0     01    02       03      04
    //  03  | 05    02       13      12

    // after second pass 
    //  0     01    02       03      04
    //  03    05  | 02       13      12

    // after third pass 
    //  0     01    02       03      04
    //  02    03    05   |   13      12

    // after fourth pass 
    //  0     01    02       03      04
    //  02    03    05       12    | 13


    int A[]={3,5,2,13,12};
    int n =5;

    
    printf("Before  applying a Selection Sort : \n");
    printArray(A,n);
    selectionsort(A,n);
    printf("After applying a Selection Sort : \n");
    printArray(A,n);

    return 0;
}