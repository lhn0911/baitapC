#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int optionnal(int arr[], int left, int right, int x)
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == x)
    {
        return mid;
    }

    if (arr[mid] < x)
    {
        return optionnal(arr, mid + 1, right, x);
    }
    else
    {
        return optionnal(arr, left, mid - 1, x);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);

    int ketQua = binarySearch(arr, 0, n - 1, x);

    if (ketQua != -1)
    {
        printf("Phan tu %d duoc tim thay tai vi tri %d\n", x, ketQua + 1);
    }
    else
    {
        printf("Khong tim thay phan tu %d trong mang\n", x);
    }

    printf("\nSu dung de quy:\n");
    ketQua = optionnal(arr, 0, n - 1, x);

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
