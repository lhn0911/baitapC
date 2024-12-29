#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int loopCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        loopCount++;

        printf("Mang sau lan lap thu %d: ", loopCount);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");

        if (swapped == 0)
        {
            break;
        }
    }
    printf("Sap xep hoan thanh sau %d lan lap.\n", loopCount);
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

    bubbleSort(arr, n);

    printf("Mang da sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
