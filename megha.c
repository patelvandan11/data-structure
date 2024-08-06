#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Linked list traversal function
void linkedListTraversal(struct node *ptr) {
    int count = 0;

    while (ptr != NULL) {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("Total number of nodes: %d\n", count);
}

// Function to reverse a linked list
struct node *reverseList(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main() {
    struct node *head, *second, *third, *fourth;

    // Allocate memory for nodes in the linked list on the heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link the nodes in the linked list
    head->data = 7;
    head->next = second;
    second->data = 11;
    second->next = third;
    third->data = 263;
    third->next = fourth;
    fourth->data = 55;
    fourth->next = NULL;

    printf("Original linked list:\n");
    linkedListTraversal(head);

    printf("\nReversed linked list:\n");
    head = reverseList(head);
    linkedListTraversal(head);

    // Free the allocated memory
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
