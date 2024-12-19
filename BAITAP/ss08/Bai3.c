#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *insertNode(Node *node, int data)
{
    if (node == NULL)
    {
        return createNode(data);
    }
    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    return node;
}
void preOrderTraversal(Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
    return;
}
void inOrderTraversal(Node *node)
{
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
    return;
}
void postOrderTraversal(Node *node)
{
    if (node != NULL)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf("%d ", node->data);
    }
    return;
}
void dinh2(struct Node *node)
{
    if (node != NULL)
        printf("Cac dinh lop 2: ");
    {
        if (node->left->left != NULL)
        {
            printf("%d ", node->left->left->data);
        }
        if (node->left->right != NULL)
        {
            printf("%d ", node->left->right->data);
        }

        if (node->right->left != NULL)
        {
            printf("%d ", node->right->left->data);
        }
        if (node->right->right != NULL)
        {
            printf("%d ", node->right->right->data);
        }
    }

    printf("\n");
}
void search(Node *node, int x)
{
    if (node == NULL)
    {
        printf("Not Found\n");
        return;
    }
    if (node->data == x)
    {
        printf("Found\n");
        return;
    }
    else if (x < node->data)
    {
        search(node->left, x);
    }
    else
    {
        search(node->right, x);
    }
}

int main()
{
    Node *tree = NULL;

    tree = insertNode(tree, 4);
    tree = insertNode(tree, 2);
    tree = insertNode(tree, 5);
    tree = insertNode(tree, 1);
    tree = insertNode(tree, 3);
    // preOrderTraversal(tree);
    // inOrderTraversal(tree);
    // postOrderTraversal(tree);
    // dinh2(tree);
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    search(tree, x);
    return 0;
}