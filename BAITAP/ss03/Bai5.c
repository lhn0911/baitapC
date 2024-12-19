#include <stdio.h>
#include <string.h>
#include <ctype.h>

int kiemTraPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1; 
    }
    while (!isalnum(str[start]) && start < end) {
        start++;
    }
    while (!isalnum(str[end]) && start < end) {
        end--;
    }
    if (tolower(str[start]) != tolower(str[end])) {
        return 0; 
    }
    return kiemTraPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if (kiemTraPalindrome(str, 0, strlen(str) - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}

