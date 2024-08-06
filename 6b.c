// ●Write a program to implement circular doubly linked list for the following operations: 
// 1. Insert a new node after the desired node 
// 2. Delete the desired note 
// 3. Display the nodes of doubly linked list


#include<stdlib.h>
#include<stdio.h>

struct node 
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node * addtoempty(int data)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node* insert_at_first(struct node *tail ,int data)
{
    struct node * newp=addtoempty(data);
    if(tail==NULL)
    {
        return newp;
    }
    else{

    struct node* temp=tail->next;
    newp->prev=tail;
    newp->next=temp;
    temp->prev=newp;
    tail->next=newp;
    return tail;
    }

}

struct node * insert_At_last(struct node* tail,int data)
{
    struct node*newp = addtoempty(data);
    if (tail==NULL)
    {
        /* code */

        return newp;

    }
    else{
        struct node * temp =tail->next;
        newp->next=temp;
        newp->prev=tail;
        tail->next=newp;
        temp->prev=newp;
        tail=newp;
        return tail;
    }
    
}

struct node* insert_after_pos(struct node* tail,int data,int pos)
{
    struct node*newp =addtoempty(data);
    if (tail==NULL)
    {
        return newp;
    }
    struct node * temp=tail->next;
    while (pos>1)
    {
        temp=temp->next;
        pos--;
    }
    newp->prev=temp;
    newp->next=temp->next;
    temp->next->prev=newp;
    temp->next=newp;
    if (temp==tail)
    {
        tail=tail->next;
    }
    return tail;
}




//  delete operation 


struct node *  delete_first_node (struct node*tail)
{
    if (tail==NULL)
    {
        return tail;
    }
    struct node* temp=tail->next;
    if(temp==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    return tail;
}


//  delete at a  last position node 

struct node * delete_the_last_node(struct node * tail)
{
    struct node * temp;
    if (tail==NULL)
    {
        return tail;
    }
    if (temp==tail)
    {
        /* code */
        free(tail);
        tail=NULL;
        return tail;
    }
    temp=tail->prev;
    temp->next=tail->next;
    temp->next->prev = temp;
    free(tail);
    tail=temp;
    return tail;
}


struct node * delete_specific_pos(struct node * tail,int pos)
{
    struct node *temp=tail->next;
    while (pos>1)
    {
        temp=temp->next;
        pos--;
    }
    struct node* temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    if (temp==tail)
    {
        tail=temp2;
    }
    return tail;
    
}
void print(struct node*tail)
{
    if(tail==NULL)
    {
        printf("no element in the list");

    }
    else{
        struct node * temp=tail->next;
        do
        {
            printf(" %d",temp->data);
            temp=temp->next;
        } while (temp!=tail->next);
        
    }
    printf("\n");
}

int main()
{
    struct node *tail= NULL;

    tail=addtoempty(1);
    printf("Empty list add a node :\n");
    print(tail);

    tail=insert_at_first(tail, 34);
    printf("After insertion at a  first position :\n");
    print(tail);


    tail=insert_At_last(tail, 2);
    printf("After insertion at the last position:\n");
    print(tail);

    tail=insert_At_last(tail, 3);
    printf("After insertion at the last position:\n");
    print(tail);


    tail=insert_after_pos(tail,4,2);  // add after the specific position 
    printf("After insertion a specific position:\n");
    print(tail);

    tail=delete_first_node(tail);
    printf("After deletion a first node :\n");
    print(tail);


    tail=delete_the_last_node(tail);
    printf("After deletion a last node :\n");
    print(tail);

    tail=delete_specific_pos(tail,2);
    printf("After deletiona sprcific position:\n");
    print(tail);
    return 0;
}   