#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertHead(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (newNode == NULL)
        return;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (newNode == NULL)
        return;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void printlist(Node *head)
{
    Node *temp = head;
    printf("NULL");
    while (temp != NULL)
    {
        printf("<=>%d<=> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Node *head = NULL;
    int value;
    do
    {
        printf("\n--------Menu ----------\n");
        printf("\n1.Them");
        printf("\n2. Xoa");
        printf("\n3. Exit");
        printf("\nChon: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int data;
            printf("\nNhap gia tri can them: ");
            scanf("%d", &data);
            insertHead(&head, data);
            printlist(head);
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            exit(0);
        }
        default:
        {
            printf("\nLua chon khong hop le!");
        }
        }
    } while (1 == 1);

    return 0;
}