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
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

int countElements(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void traverseFromStart(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sach trong\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n, i, value;
    Node *head = NULL;

    printf("Nhap so luong phan tu trong danh sach (n): ");
    scanf("%d", &n);

    if (n > 0)
    {
        printf("Nhap cac phan tu cua danh sach:\n");
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("Danh sach ban dau:\n");
    traverseFromStart(head);

    int elementCount = countElements(head);
    printf("So phan tu trong danh sach: %d\n", elementCount);

    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
