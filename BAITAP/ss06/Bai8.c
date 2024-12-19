#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút trong danh sách liên kết
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Định nghĩa cấu trúc ngăn xếp
typedef struct
{
    Node *top;
} Stack;

// Khởi tạo ngăn xếp
void initStack(Stack *s)
{
    s->top = NULL;
}

// Kiểm tra ngăn xếp rỗng
int isEmpty(Stack *s)
{
    return s->top == NULL;
}

// Thêm một phần tử vào ngăn xếp
void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Day.");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Lấy phần tử trên cùng ra khỏi ngăn xếp
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Rong.");
        return -1; // Giá trị báo lỗi
    }
    Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

// Xem giá trị phần tử trên cùng mà không lấy nó ra
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Rong.");
        return -1; // Giá trị báo lỗi
    }
    return s->top->data;
}

// Chương trình chính kiểm tra các thao tác ngăn xếp
int main()
{
    Stack s;
    initStack(&s);

    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    // Nhập các phần tử và thêm vào ngăn xếp
    for (int i = 0; i < n; i++)
    {
        printf("Nhap gia tri phan tu %d: ", i + 1);
        scanf("%d", &value);
        push(&s, value);
    }

    // Hiển thị phần tử trên cùng
    printf("Phan tu tren cung: %d\n", peek(&s));

    // Lấy các phần tử ra khỏi ngăn xếp
    while (!isEmpty(&s))
    {
        printf("Lay ra: %d\n", pop(&s));
    }

    // Kiểm tra ngăn xếp rỗng
    if (isEmpty(&s))
    {
        printf("Rong.\n");
    }

    return 0;
}