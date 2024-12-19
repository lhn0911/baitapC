#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct{
	int array[MAX];
	int top;
	
}Stack;
void inital(Stack* stack){
	stack->top=-1;
	
}
int isEmpty(Stack* stack){
	if(stack->top==-1){
		return 1;
	}
	return 0;
}
int isFull(Stack* stack){
	if(stack->top>=MAX-1){
		return 1;
	}
	return 0;
}
void push(Stack* stack,int value){
	if(isFull(stack)==1){
		printf("Day");
		return;
	}
	stack->array[++(stack->top)]=value;
}
void printStack(Stack* stack){
	for(int i=stack->top;i>=0;i--){
		printf("%d/n",stack->array[i]);
	} 
}
int main(){
	int value;
	Stack stack;
	inital(&stack);
	do{
		printf("------Menu--------\n");
		printf("1.Them\n");
		printf("2.Danh sach\n");
		printf("0.Thoat\n");
		printf("Chon\n");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("nhap vao gia tri can them");
				scanf("%d",&value);
				push(&stack,value);
				break;
			case 2:
				printStack(value);
				break;
			case 3:
				exit(0);
		}
		
	}while(1==1);
	return 0;
}
