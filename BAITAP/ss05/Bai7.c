#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int value)
{
    Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach khong con phan tu nao\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

void deleteNode(Node **head, Node *nodeToDelete)
{
    if (*head == NULL || nodeToDelete == NULL)
        return;

    if (*head == nodeToDelete)
    {
        *head = nodeToDelete->next;
    }

    if (nodeToDelete->next != NULL)
    {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    if (nodeToDelete->prev != NULL)
    {
        nodeToDelete->prev->next = nodeToDelete->next;
    }

    free(nodeToDelete);
}

void removeEven(Node **head)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        Node *nextNode = temp->next;
        if (temp->data % 2 == 0)
        {
            deleteNode(head, temp);
        }
        temp = nextNode;
    }
}

void sortList(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    Node *i;
    Node *j;
    for (i = *head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main()
{
    Node *head = NULL;
    int n, value;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n == 0)
    {
        printf("Danh sach khong con phan tu nao\n");
        return 0;
    }

    printf("Nhap cac phan tu: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sach ban dau: ");
    printList(head);

    removeEven(&head);

    if (head == NULL)
    {
        printf("Danh sach khong con phan tu nao\n");
        return 0;
    }

    sortList(&head);

    printf("Danh sach sau khi xoa so chan va sap xep: ");
    printList(head);

    return 0;
}
