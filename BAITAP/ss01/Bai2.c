#include <stdio.h>

int main() {
    int n, x;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }

    int arr[n];
    printf("Nhap gia tri phan tu: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap so muon tim: ");
    scanf("%d", &x);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }

    printf("So %d xuat hien %d lan trong mang.\n", x, count);

    return 0;
}

