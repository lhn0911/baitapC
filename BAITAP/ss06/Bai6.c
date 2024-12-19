#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
        return '\0';
    }
    return stack->data[stack->top--];
}

bool isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isValidExpression(const char *expression)
{
    Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char current = expression[i];

        if (current == '(' || current == '{' || current == '[')
        {
            push(&stack, current);
        }
        else if (current == ')' || current == '}' || current == ']')
        {
            if (isEmpty(&stack))
            {
                return false;
            }
            char top = pop(&stack);
            if (!isMatchingPair(top, current))
            {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main()
{
    char expression[MAX];

    printf("Nhap bieu thuc: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0';

    if (isValidExpression(expression))
    {
        printf("Bieu thuc hop le\n");
    }
    else
    {
        printf("Bieu thuc khong hop le\n");
    }

    return 0;
}
