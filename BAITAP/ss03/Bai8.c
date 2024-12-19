#include <stdio.h>

int countPaths(int m, int n)
{
    if (m == 1 || n == 1)
    {
        return 1;
    }
    return countPaths(m - 1, n) + countPaths(m, n - 1);
}

int main()
{
    int m, n;

    printf("Nhap so hang (M): ");
    scanf("%d", &m);
    printf("Nhap so cot (N): ");
    scanf("%d", &n);

    int result = countPaths(m, n);
    printf("Tong so duong di tu (0,0) den (%d,%d) la: %d\n", m - 1, n - 1, result);

    return 0;
}
