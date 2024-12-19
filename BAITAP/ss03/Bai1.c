#include<stdio.h>
int tinhGiaithua(int n){
	if (n == 0 || n == 1) {
        return 1;
    }
    return n * tinhGiaithua(n - 1); 
}
int main(){
	int n;
    printf("Nhap so n: ");
    scanf("%d", &n);

    if (n < 0 || n > 100) { 
        printf("Gia tri n khong hop le!\n");
        return 1;
    }

    int giaithua = tinhGiaithua(n); 
    printf("Giai thua cua %d la: %d\n", n, giaithua);

	return 0;
}
