#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int score;
} Student;

int main()
{
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Khong co sinh vien nao\n");
        return 0;
    }

    Student students[n];

    for (int i = 0; i < n; i++)
    {
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Nhap diem cua %s: ", students[i].name);
        scanf("%d", &students[i].score);
    }

    char searchName[50];

    printf("Nhap ten sinh vien can tim: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(students[i].name, searchName) == 0)
        {
            printf("Diem cua %s la: %d\n", students[i].name, students[i].score);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Khong tim thay sinh vien.\n");
    }

    return 0;
}
