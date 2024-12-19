#include <stdio.h>

int combination(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return combination(n - 1, k - 1) + combination(n - 1, k);
}

int main()
{
    int n, k;

    printf("Nhap n: ");
    scanf("%d", &n);

    printf("Nhap k: ");
    scanf("%d", &k);

    if (k > n || n < 0 || k < 0)
    {
        printf("du lieu khong hop le\n");
    }
    else
    {
        printf("C(%d, %d) = %d\n", n, k, combination(n, k));
    }

    return 0;
}
