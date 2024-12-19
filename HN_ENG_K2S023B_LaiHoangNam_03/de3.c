#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Stack
{
    int data[MAX];
    int top;
} Stack;

void init(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Ngan xep day\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong\n");
        return -1;
    }
    int value = s->data[s->top--];
    printf("Da lay phan tu %d ra khoi ngan xep\n", value);

    return value;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong\n");
        return -1;
    }
    return s->data[s->top];
}

int size(Stack *s)
{
    return s->top + 1;
}

void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong\n");
        return;
    }
    printf("Cac phan tu trong ngan xep: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

void clear(Stack *s)
{
    s->top = -1;
    printf("Ngan xep da duoc xoa\n");
}

void reverse(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Ngan xep rong\n");
        return;
    }
    printf("Cac phan tu trong ngan xep (dao nguoc): ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main()
{
    Stack s;
    init(&s);
    int choice, value, n;

    do
    {
        printf("=========== MENU ===========\n");
        printf("1. Them phan tu vao ngan xep\n");
        printf("2. Lay phan tu khoi ngan xep\n");
        printf("3. Xem phan tu tren cung cua ngan xep\n");
        printf("4. Kiem tra ngan xep co rong khong\n");
        printf("5. Lay kich thuoc ngan xep\n");
        printf("6. In toan bo ngan xep\n");
        printf("7. Xoa toan bo ngan xep\n");
        printf("8. In ngan xep theo thu tu nguoc lai\n");
        printf("9. Thoat\n");
        printf("============================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Nhap so luong phan tu can them: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &value);
                push(&s, value);
            }
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            value = peek(&s);
            if (value != -1)
            {
                printf("Phan tu tren cung: %d\n", value);
            }
            break;
        case 4:
            printf("Ngan xep %s rong.\n", isEmpty(&s) ? "la" : "khong");
            break;
        case 5:
            printf("Kich thuoc ngan xep: %d\n", size(&s));
            break;
        case 6:
            display(&s);
            break;
        case 7:
            clear(&s);
            break;
        case 8:
            reverse(&s);
            break;
        case 9:
            printf("Thoat\n");
            exit(0);
        default:
            printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (1);

    return 0;
}
