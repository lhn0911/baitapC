#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int swapCount = 0;

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

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swapCount++;

            printf("Hoan doi: ");
            for (int k = 0; k < n; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }

    printf("Sap xep hoan thanh voi %d lan hoan doi.\n", swapCount);
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
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("Mang da sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}