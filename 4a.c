/*    Write a program for single linked list for the following operations: 
// 1. Count the number of nodes in a given linked list 
// 2. Delete the desired node from linked list 
// 3. Insert the new node after the desired node into the linked list
// 4. Create a new list by reversing the list
5. Concatenates two linked list    */


#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
void linkdlisttraversal(struct node *ptr)
{ int count=0 ;

    while (ptr != NULL)
    {
        printf("element :%d \n", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("value of total number of nodes  is a : %d",count);
}
// 1. insertion at a first
struct node *insertat_first(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
// 2.insert in between
struct node *insert_at_index(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// 3.insert at the end
struct node *insert_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// 4.insert after a node
struct node *insert_at_after_node(struct node *head, struct node *previous_node, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = previous_node->next;
    previous_node->next = ptr;
    return head;
}

//  case 1 : delete at a  first element of a linked list 
struct node *delete_first(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// case 2:deleteing the element at the given index
struct node *delete_at_index(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
// case 3: deleting the last element
struct node *delete_last(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}
// case 4:deleteing the element the given value
struct node *delete_at_givel_valu(struct node *head, int valu)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != valu && q->next == NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == valu)
    {
        p->next = q->next;
        free(q);
    }
    return head;
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
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node* appendnode(struct node* head, int data) {
    struct node* newnode = createnode(data);
    if (head == NULL) {
        return newnode;
    }

    struct node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    return head;
}
void displayList(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
struct node*  concatenateLists(struct node* list1,struct node* list2) {
    if (list1 == NULL) {
        return list2;
    }

   struct node* ptr = list1;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = list2;

    return list1;
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
   
     struct  node* list1 = NULL;
     list1 = appendnode(list1, 1);
     list1 = appendnode(list1, 2);
     list1 = appendnode(list1, 3);

     struct node* list2 = NULL;
     list2 = appendnode(list2, 4);
     list2 = appendnode(list2, 5);
     list2 = appendnode(list2, 6);
    

    // freeList(list1);
    char value;
    printf("A.Count the number of nodes in a given linked list.\n");
    printf("B.Delete the first node from linked list.\n");
    printf("C.Delete the given index / desired node from linked list.\n");
    printf("D.Delete the last node from linked list.\n");
    printf("E.Delete the node given value from linked list.\n");
    printf("F.Insert the new node after the desired node into the linked list.\n");
    printf("G.Insert the new node at a first position into the linked list.\n");
    printf("H.Insert the new node at a last position into the linked list.\n");
    printf("I.Insert the new node at a specific index into the linked list.\n");
    printf("J.Create a new list by reversing the list.\n");
    printf("K.Concatenates two linked list.\n");
    scanf("%c",&value);
    
    switch (value)
    {
    case 'K':
        printf("List 1: ");
        displayList(list1);
        printf("List 2: ");
        displayList(list2);
        list1 = concatenateLists(list1, list2);
        printf("Concatenated List: ");
        displayList(list1);
        break;
    case 'J':
        printf("Original linked list:\n");
        linkdlisttraversal(head);
        printf("\nReversed linked list:\n");
        head = reverseList(head);
        linkdlisttraversal(head);
        break;
    case 'I':
        head = insert_at_index(head, 54, 1);
        linkdlisttraversal(head);
        break;
    case 'H':
        linkdlisttraversal(head);
        head = insert_at_end(head, 56);
        break;
    case 'G':
        linkdlisttraversal(head);
        head = insertat_first(head, 1);
        break;
    case 'F':
        head = insert_at_after_node(second, third, 99);
        linkdlisttraversal(head);
        break;
    case 'E':
        head = delete_at_givel_valu(head, 11);
        linkdlisttraversal(head);
        break;
    case 'D':
        head = delete_last(head);
        linkdlisttraversal(head);
    case 'C':
        head = delete_at_index(head, 2);
        linkdlisttraversal(head);
    case 'B':
        head = delete_first(head);
        linkdlisttraversal(head);
    case 'A':
       linkdlisttraversal(head);
    default:
        break;
    }
    
    // Free the allocated memory
    free(head);
    free(second);
    free(third);
    free(fourth);
    return 0;
}
