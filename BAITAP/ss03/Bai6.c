#include <stdio.h>

int tinhTongMang(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n - 1] + tinhTongMang(arr, n - 1);
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tong cac phan tu cua mang: 0\n");
        return 0;
    }

    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int tong = tinhTongMang(arr, n);
    printf("Tong cac phan tu cua mang: %d\n", tong);

    return 0;
}

