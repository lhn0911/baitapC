#include <stdio.h>

int linearsearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3, 5, 7, 9, 2, 8, 10, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    int ketQua = linearsearch(arr, n, x);

    if (ketQua != -1)
    {
        printf("Phan tu %d duoc tim thay tai vi tri %d\n", x, ketQua + 1);
    }
    else
    {
        printf("Khong tim thay phan tu %d trong mang\n", x);
    }

    return 0;
}