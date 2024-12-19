#include <stdio.h>

int main() {
    int n, m;

    printf("Nhap so luong phan tu cua mang 1: ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        return 1;
    }

    int arr1[n];
    if (n > 0) {
        printf("Nhap gia tri phan tu 1: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr1[i]);
        }
    }

    printf("Nhap so luong phan tu cua mang 2: ");
    scanf("%d", &m);

    if (m < 0 || m > 1000) {
        return 1;
    }

    int arr2[m];
    if (m > 0) {
        printf("Nhap gia tri phan tu 2: ", m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &arr2[i]);
        }
    }

    int result[n + m];
    for (int i = 0; i < n; i++) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < m; i++) {
        result[n + i] = arr2[i];
    }

    printf("Mang sau khi gop: [");
    for (int i = 0; i < n + m; i++) {
        printf("%d", result[i]);
        if (i != n + m - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}

