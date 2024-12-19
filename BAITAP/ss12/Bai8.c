#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Mang rong\n");
        return 0;
    }

    int arr[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    char condition[20];
    printf("Nhap dieu kien tim kiem (chan/le/lon hon 0): ");
    scanf("%s", condition);

    int found = 0;

    if (strcmp(condition, "chan") == 0)
    {
        printf("Cac so chan la: ");
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                printf("%d ", arr[i]);
                found = 1;
            }
        }
    }
    else if (strcmp(condition, "le") == 0)
    {
        printf("Cac so le la: ");
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
            {
                printf("%d ", arr[i]);
                found = 1;
            }
        }
    }
    else if (strcmp(condition, "lon hon 0") == 0)
    {
        printf("Cac so lon hon 0 la: ");
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                printf("%d ", arr[i]);
                found = 1;
            }
        }
    }
    else
    {
        printf("Dieu kien khong hop le.\n");
        return 0;
    }

    if (!found)
    {
        printf("Khong co so nao thoa man dieu kien.\n");
    }
    else
    {
        printf("\n");
    }

    return 0;
}
