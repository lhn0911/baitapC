#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Mang ban dau: ");
    printArr(arr, size);
    printf("\n");
    selectionSort(arr, size);
    printf("Mang da sap xep: ");
    printArr(arr, size);
    return 0;
}