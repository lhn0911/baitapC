#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 1000

// Cấu trúc ngăn xếp
typedef struct
{
    char data[MAX];
    int top;
} Stack;

// Khởi tạo ngăn xếp
void initStack(Stack *s)
{
    s->top = -1;
}

// Kiểm tra ngăn xếp rỗng
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Kiểm tra ngăn xếp đầy
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// Đẩy phần tử vào ngăn xếp
void push(Stack *s, char c)
{
    if (!isFull(s))
    {
        s->data[++(s->top)] = c;
    }
}

// Lấy phần tử ra khỏi ngăn xếp
char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[(s->top)--];
    }
    return '\0';
}

// Hàm làm sạch chuỗi: loại bỏ khoảng trắng và chuyển ký tự thành chữ thường
void cleanString(const char *input, char *cleaned)
{
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalnum(input[i]))
        { // Giữ lại ký tự chữ và số
            cleaned[j++] = tolower(input[i]);
        }
    }
    cleaned[j] = '\0'; // Kết thúc chuỗi sạch
}

// Hàm kiểm tra tính đối xứng
int isPalindrome(const char *cleaned)
{
    int length = strlen(cleaned);
    Stack stack;
    initStack(&stack);

    // Đẩy nửa đầu chuỗi vào ngăn xếp
    for (int i = 0; i < length / 2; i++)
    {
        push(&stack, cleaned[i]);
    }

    // Bỏ qua ký tự giữa nếu chuỗi có độ dài lẻ
    int start = (length % 2 == 0) ? length / 2 : length / 2 + 1;

    // So sánh nửa sau với ngăn xếp
    for (int i = start; i < length; i++)
    {
        if (pop(&stack) != cleaned[i])
        {
            return 0; // Không đối xứng
        }
    }

    return 1; // Đối xứng
}

int main()
{
    char input[MAX], cleaned[MAX];

    printf("Nhap vao 1 chuoi: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng

    cleanString(input, cleaned);

    if (isPalindrome(cleaned))
    {
        printf("Chuoi nay doi xung.\n");
    }
    else
    {
        printf("Chuoi nay ko doi xung.\n");
    }

    return 0;
}