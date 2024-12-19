#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 100

int hashFunction(int key)
{
    return abs(key) % V;
}

void insertHashTable(bool hashTable[], int key)
{
    int index = hashFunction(key);
    hashTable[index] = true;
}

bool searchHashTable(bool hashTable[], int key)
{
    int index = hashFunction(key);
    return hashTable[index];
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
    bool hashTable[V] = {false};

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        insertHashTable(hashTable, arr[i]);
    }

    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);

    if (searchHashTable(hashTable, x))
    {
        printf("So %d da duoc tim thay trong mang.\n", x);
    }
    else
    {
        printf("So %d khong co trong mang.\n", x);
    }

    return 0;
}
