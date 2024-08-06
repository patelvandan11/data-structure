//  Demonstrate the concept of Call by value and Call by Reference. 

#include <stdio.h>

void swapByValue(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
   
}


void swapByReference(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
}

int main() {
    int x = 10, y = 20;
    int choice;

    printf("Enter 1 for swap by value, 2 for swap by reference: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Before swap By Value function: x = %d, y = %d\n", x, y);
            swapByValue(x, y);
            printf("After swap By Value function: x = %d, y = %d\n", y , x);
            break;
        case 2:
            printf("Before swap By Reference function: x = %d, y = %d\n", x, y);
            swapByReference(&x, &y);
            printf("After swap By Reference function: x = %d, y = %d\n", x, y);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}