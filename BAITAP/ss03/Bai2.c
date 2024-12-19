#include<stdio.h>
int tinhTong(int n,int m){
	if (n > m) {
        return 0;
    }
    return n + tinhTong(n + 1, m);
}
int main(){
	int n, m;
    printf("Nhap so n, m: ");
    scanf("%d %d", &n, &m);

    if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }

    int tong = tinhTong(n, m); 
    printf("Tong:%d\n",tong);
	return 0;
}
