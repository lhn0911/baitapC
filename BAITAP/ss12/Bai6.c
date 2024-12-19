#include <stdio.h>

void findDuplicates(int arr[], int n)
{
    int foundDuplicate = 0;

    printf("Cac phan tu lap lai trong mang:\n");
    for (int i = 0; i < n; i++)
    {
        int count = 1;

        if (arr[i] == -1)
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                arr[j] = -1;
            }
        }

        if (count > 1)
        {
            printf("Phan tu %d xuat hien %d lan.\n", arr[i], count);
            foundDuplicate = 1;
        }
    }

    if (!foundDuplicate)
    {
        printf("Khong co phan tu lap lai trong mang.\n");
    }
}

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

    findDuplicates(arr, n);

    return 0;
}
