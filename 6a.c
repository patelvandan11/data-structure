// ●Write a program to implement doubly linked list for the following operations: 
// 1. Insert a new node after the desired node 
// 2. Delete the desired note 
// 3. Display the nodes of doubly linked list



#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node* insert_at_first(struct node * head , int data )
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct node* addtoempty(struct node *head, int data)
{
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* addatend(struct node* head, int data)
{
    struct node* temp, *tp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while (tp->next != NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}

struct node * insert_after_specific_pos(struct node* head, int data, int position)
{
    struct node * newp=NULL;
    struct node * temp=head;
    struct node * temp2=NULL;
    newp=addtoempty(newp,data);
    while (position !=1)
    {
        temp=temp->next;
        position--;
    }
    if (temp->next==NULL)
    {
        temp->next=newp;
        newp->prev=temp;
    }
    else
    {
        temp2 =temp->next;
        temp->next=newp;
        temp2->prev=newp;
        newp->next=temp2;
        newp->prev=temp;
    }
    return head;
}
struct node * insert_at_a_specific_pos(struct node* head , int data , int position)
{
    struct node * newp=NULL;
    struct node * temp =head;
    struct node * temp2=NULL;
    newp=addtoempty(newp,data);

    int pos=position;
    while(pos>2)
    {
        temp=temp->next;
        pos--;

    }
    if (position==1)
    {
        head=insert_at_first(head,data);

    }
    else
    {
        temp2=temp->next;
        temp->next=newp;
        temp2->prev=newp;
        newp->next=temp2;
        newp->prev=temp;
    }
    return head;
}
struct node* delete_first_node(struct node* head)
{
    struct node* temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    head->prev = NULL;
    return head;
}

struct node * delete_last_node(struct node * head)
{
    struct node*temp=head;
    struct node * temp2;
    while (temp->next !=NULL)
    {
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    return head;
    
}


struct node* delete_a_specific_node(struct node * head, int position)
{
    struct node * temp=head;
    struct node* temp2=NULL;
    if (position==1)
    {
        /* code */
        head=delete_first_node(head);
        return head;
    }
    while (position>1)
    {
        /* code */
        temp=temp->next;
        position--;

    }
    if (temp->next==NULL)
    {
        head=delete_last_node(head);
    }
    else
    {
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head;
}

void print(struct node* head)
{
    struct node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}




int main()
{
    struct node* head = NULL;
    struct node* ptr;

    head = addtoempty(head, 34);
    head = addatend(head, 45);
    head = addatend(head, 9);


    printf("Before deletion:\n");
    print(head);



    // head = delete_first_node(head);  // delete a first node of a linked list 
    // printf("After deletion:\n");
    // print(head);
    // //  1  2   
    
    // head=delete_last_node(head);  // delete a last node  in a doubly linked list 
    // printf("After deletion:\n");
    // print(head);

    // head=delete_a_specific_node(head,2); // deleate a intermidiate node in a linked list 
    // printf("After deletion:\n");
    // print(head);
    
    // head=insert_at_first(head,2);  // insertion at a  first position 
    // printf("After deletion:\n");
    // print(head);


    // head=insert_after_specific_pos(head,25,2);  // insertion after a specific position 
    // printf("After deletion:\n");
    // print(head);


    // head = addtoempty(head, 99); // delete a whole linked list and insert a  node
    // printf("After deletion:\n");
    // print(head);

    head = insert_at_a_specific_pos(head, 25,3); // insert ata specific position
    printf("After deletion:\n");
    print(head);



    return 0;
}
