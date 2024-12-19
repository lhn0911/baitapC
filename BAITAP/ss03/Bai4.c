#include<stdio.h>
#include<string.h>
void daonguocChuoi(char str[],int start,int end){
	if(start>=end){
		return;
	}
	char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    daonguocChuoi(str, start + 1, end - 1);
}
int main(){
	 char str[100];

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    daonguocChuoi(str, 0, strlen(str) - 1);

    printf("Chuoi dao nguoc: %s\n", str);
	return 0;
}
