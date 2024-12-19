#include <stdio.h>

int main() {
    int n, k, found = 0;


    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);


    if (n <= 0 || n > 100) {
        return 1;
    }

    int arr[n];
    printf("Nhap gia tri phan tu: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

  
    printf("Nhap phan tu k can xoa: ");
    scanf("%d", &k);

  
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            found = 1;
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1]; 
            }
            n--; 
            break;
        }
    }

    if (found) {
        printf("Mang sau khi xoa: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Thong bao khong co phan tu day\n");
    }

    return 0;
}

