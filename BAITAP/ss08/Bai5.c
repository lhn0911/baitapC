#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int search(Node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    Node *root = NULL;

    // chen va duyet
    int values1[] = {5, 3, 7, 2, 4, 6, 8};
    int n1 = sizeof(values1) / sizeof(values1[0]);
    for (int i = 0; i < n1; i++)
    {
        root = insertNode(root, values1[i]);
    }
    printf("Duyet cay theo thu tu inorder: ");
    inorderTraversal(root);
    printf("\n");

    freeTree(root);
    root = NULL;

    // tim kiem
    int values2[] = {10, 5, 15, 2, 7, 12, 20};
    int n2 = sizeof(values2) / sizeof(values2[0]);
    for (int i = 0; i < n2; i++)
    {
        root = insertNode(root, values2[i]);
    }
    int searchValue2 = 7;
    if (search(root, searchValue2))
    {
        printf("Gia tri %d ton tai trong cay.\n", searchValue2);
    }
    else
    {
        printf("Gia tri %d khong ton tai trong cay.\n", searchValue2);
    }

    int searchValue3 = 8;
    if (search(root, searchValue3))
    {
        printf("Gia tri %d ton tai trong cay.\n", searchValue3);
    }
    else
    {
        printf("Gia tri %d khong ton tai trong cay.\n", searchValue3);
    }

    freeTree(root);

    return 0;
}
