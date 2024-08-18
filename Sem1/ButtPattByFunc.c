#include <stdio.h>
void makepat(int num){
	int i, j;
	for(i = 1;i<=num;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		for (j=1;j<=2*(num-i);j++){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	for(i = 1;i<=num;i++){
		for(j=1;j<=num-i;j++){
			printf("*");
		}
		for (j=1;j<=2*(i);j++){
			printf(" ");
		}
		for(j=1;j<=num-i;j++){
			printf("*");
		}
		printf("\n");
	}
}
int main(){
	printf("Enter the number of rows you want to see in the first half of butterfly pattern : \n");
	int num;
	scanf("%d", &num);
	makepat(num);
}
