#include <stdio.h>
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
int binarySearch(int arr[], int n, int target)
{

    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
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
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;

    printf("Nhap vao so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("So luong phan tu phai lon hon 0.\n");
        return 1;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    int target;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);
    if (result != -1)
    {
        printf("Phan tu %d duoc tim thay tai vi tri %d\n", target, result + 1);
    }
    else
    {
        printf("Khong tim thay phan tu %d\n", target);
    }

    return 0;
}
