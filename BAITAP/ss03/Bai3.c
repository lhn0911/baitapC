#include<stdio.h>
int soLan(int n){
	if (n == 0) {
        return 0; 
    }
    if (n == 1) {
        return 1; 
    }
    return soLan(n - 1) + soLan(n - 2);
}
int main(){
	int n;
    printf("Nhap so lan hien thi Fibonacci n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So lan hien thi phai lon hon 0.\n");
        return 1;
    }

    printf("Day Fibonacci:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", soLan(i));
        if (i < n - 1) {
            printf(", "); 
        }
    }
    printf("\n");

	return 0;
}
