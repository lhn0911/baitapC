#include <stdio.h>
#include <stdlib.h>

// Khai báo cấu trúc Node
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Hàm tạo một node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm node vào cuối danh sách
void append(Node **head, int data)
{
    Node *newNode = createNode(data);
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

// Hàm in danh sách liên kết
void printList(Node *head)
{
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

// Hàm chèn danh sách con vào danh sách chính tại vị trí cho trước
void insertSublist(Node **mainList, Node *subList, int position)
{
    if (position < 0)
    {
        printf("Vi tri chen khong hop le.\n");
        return;
    }

    Node *temp = *mainList;
    int count = 0;

    // Duyệt đến vị trí chèn
    while (temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }

    // Kiểm tra vị trí có hợp lệ không
    if (temp == NULL && count != position)
    {
        printf("Vi tri chen khong hop le.\n");
        return;
    }

    if (temp == NULL)
    { // Chèn vào cuối danh sách chính
        Node *tail = *mainList;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = subList;
        subList->prev = tail;
    }
    else if (temp->prev == NULL)
    { // Chèn vào đầu danh sách chính
        subList->prev = NULL;
        Node *subTail = subList;
        while (subTail->next != NULL)
        {
            subTail = subTail->next;
        }
        subTail->next = temp;
        temp->prev = subTail;
        *mainList = subList;
    }
    else
    { // Chèn vào giữa danh sách chính
        Node *subTail = subList;
        while (subTail->next != NULL)
        {
            subTail = subTail->next;
        }
        subTail->next = temp;
        if (temp != NULL)
        {
            temp->prev = subTail;
        }
        subList->prev = temp->prev;
        temp->prev->next = subList;
    }
}

int main()
{
    Node *mainList = NULL;
    Node *subList = NULL;

    // Tạo danh sách chính
    append(&mainList, 1);
    append(&mainList, 2);
    append(&mainList, 3);
    append(&mainList, 4);
    append(&mainList, 5);

    // Tạo danh sách con
    append(&subList, 10);
    append(&subList, 20);
    append(&subList, 30);

    printf("Danh sach chinh: ");
    printList(mainList);
    printf("Danh sach con: ");
    printList(subList);

    int position = 2;
    printf("Chen danh sach con vao vi tri %d\n", position);
    insertSublist(&mainList, subList, position);

    printf("Danh sach sau khi chen: ");
    printList(mainList);

    return 0;
}