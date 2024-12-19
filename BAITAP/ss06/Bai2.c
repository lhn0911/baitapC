#include <stdio.h>
#define MAX_SIZE 100

typedef struct Stack
{
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Ngan xep day\n");
        return;
    }
    stack->data[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ngan xep rong\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void printStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ngan xep rong\n");
        return;
    }
    printf("Cac phan tu trong ngan xep con lai:\n");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->data[i]);
    }
}

int main()
{
    Stack stack;
    initStack(&stack);

    int n, value;

    printf("Nhap so luong phan tu can them vao ngan xep (toi da %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE)
    {
        printf("So luong phan tu vuot qua kich thuoc toi da\n");
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&stack, value);
    }

    if (!isEmpty(&stack))
    {
        int poppedValue = pop(&stack);
        printf("Phan tu bi xoa: %d\n", poppedValue);
    }
    else
    {
        printf("Ngan xep rong\n");
    }

    printStack(&stack);

    return 0;
}
