#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct Stack
{
    char data[MAX];
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

void push(Stack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Ngan xep day\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Ngan xep rong\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

int main()
{
    Stack stack;
    initStack(&stack);

    char input[MAX], reversed[MAX];
    int i;

    printf("Nhap mot chuoi: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0';

    for (i = 0; input[i] != '\0'; i++)
    {
        push(&stack, input[i]);
    }

    i = 0;
    while (!isEmpty(&stack))
    {
        reversed[i++] = pop(&stack);
    }
    reversed[i] = '\0';

    printf("Chuoi dao nguoc: %s\n", reversed);

    return 0;
}
