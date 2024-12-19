#include <stdio.h>

int main() {
    int n, k;


    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);


    if (n <= 0 || n > 1000) {
        return 1;
    }

    int arr[n];

    printf("Nhap gia tri phan tu : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri k: ");
    scanf("%d", &k);

    int found = 0; 
    printf("Cac cap so co tong bang %d: ", k);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                if (found) {
                    printf(", ");
                }
                printf("%d,%d", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Khong tim thay cap so nao co tong bang %d.\n", k);
    } else {
        printf("\n");
    }

    return 0;
}

