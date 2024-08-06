// 7 ●Write a program to construct binary search tree.
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int Data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->Data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int Data) 
{
    if (node == NULL) return newNode(Data);

    if (Data < node->Data)
        node->left = insert(node->left, Data);
    else if (Data > node->Data)
        node->right = insert(node->right, Data);

    return node;
}

void inorderTraversal(struct Node* root) 
{
    if (root != NULL) 
    {
        inorderTraversal(root->left);
        printf("%d ", root->Data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int A[] = {11,5,20,14,8,9,12,15,200};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++)
    {
        root = insert(root, A[i]);
    }
    printf("Inorder traversal of the constructed BST:\n");
    inorderTraversal(root);

    return 0;
}
