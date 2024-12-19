#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Stack
{
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX - 1;
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

void checkEmpty(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ngan xep rong\n");
    }
}

int main()
{
    Stack stack;
    initStack(&stack);

    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n > 0)
    {
        printf("Nhap gia tri phan tu:\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &value);
            push(&stack, value);
        }
    }

    checkEmpty(&stack);

    return 0;
}
