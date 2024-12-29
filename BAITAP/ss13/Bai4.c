#include <stdio.h>

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        printf("Step %d: ", i);
        displayArray(arr, size);
    }
}

int main()
{
    int n;

    printf("Nhap vao so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhap gia tri cac phan tu: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    displayArray(arr, n);
    insertionSort(arr, n);

    printf("Mang da sap xep: ");
    displayArray(arr, n);

    return 0;
}
