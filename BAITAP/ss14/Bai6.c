#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n;

    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhap cac phan tu cua mang: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Mang sau khi sap xep: \n");
    printArray(arr, n);

    int x;

    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int linearResult = linearSearch(arr, n, x);
    if (linearResult != -1)
    {
        printf("Tim thay %d bang tim kiem tuyen tinh tai vi tri %d\n", x, linearResult);
    }
    else
    {
        printf("Khong tim thay %d bang tim kiem tuyen tinh\n", x);
    }

    int binaryResult = binarySearch(arr, n, x);
    if (binaryResult != -1)
    {
        printf("Tim thay %d bang tim kiem nhi phan tai vi tri %d\n", x, binaryResult);
    }
    else
    {
        printf("Khong tim thay %d bang tim kiem nhi phan\n", x);
    }

    return 0;
}
