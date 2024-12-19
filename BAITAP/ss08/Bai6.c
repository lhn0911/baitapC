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

int isBSTUtil(Node *node, int min, int max)
{
    if (node == NULL)
    {
        return 1;
    }

    if (node->data <= min || node->data >= max)
    {
        return 0;
    }
    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data, max);
}

int isBST(Node *root)
{
    return isBSTUtil(root, -2147483648, 2147483647);
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
    Node *root1 = createNode(10);
    root1->left = createNode(5);
    root1->right = createNode(15);
    root1->left->left = createNode(3);
    root1->left->right = createNode(7);
    root1->right->left = createNode(12);
    root1->right->right = createNode(20);

    if (isBST(root1))
    {
        printf("Cay la cay nhi phan tim kiem (BST).\n");
    }
    else
    {
        printf("Cay khong phai la cay nhi phan tim kiem (BST).\n");
    }

    freeTree(root1);

    Node *root2 = createNode(10);
    root2->left = createNode(5);
    root2->right = createNode(15);
    root2->left->left = createNode(6);
    root2->left->right = createNode(7);
    root2->right->left = createNode(12);
    root2->right->right = createNode(20);

    if (isBST(root2))
    {
        printf("Cay la cay nhi phan tim kiem (BST).\n");
    }
    else
    {
        printf("Cay khong phai la cay nhi phan tim kiem (BST).\n");
    }

    freeTree(root2);

    printf("\nTest case 3:\n");
    Node *root3 = NULL;

    if (isBST(root3))
    {
        printf("Cay la cay nhi phan tim kiem (BST).\n");
    }
    else
    {
        printf("Cay khong phai la cay nhi phan tim kiem (BST).\n");
    }

    return 0;
}
