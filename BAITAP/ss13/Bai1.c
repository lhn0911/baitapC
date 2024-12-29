#include <stdio.h>
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int swap = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            swap = 1;
        }

        if (swap == 0)
        {
            break;
        }
    }
}
void printfArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {6, 4, 3, 7, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Mang ban dau: ");
    printfArr(arr, n);
    bubbleSort(arr, n);
    printf("Mang sau khi sap xep: ");
    printfArr(arr, n);
    return 0;
}
