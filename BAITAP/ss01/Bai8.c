#include <stdio.h>

int main() {
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        return 1;
    }

    int arr[n - 1];

    printf("Nhap gia tri phan tu : ", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int total_sum = n * (n + 1) / 2;

    int arr_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        arr_sum += arr[i];
    }

    int missing_number = total_sum - arr_sum;

    printf("So bi thieu: %d\n", missing_number);

    return 0;
}

