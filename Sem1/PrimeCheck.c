#include <stdio.h>
int main(){
	int i, num, a = 1;
	printf("Enter the number of your choice : \n");
	scanf("%d", &num);
	for (i= 2; i<num; i++){
		if (num%i==0){
			a = 0;
		}
	}
	if (a==0){
		printf("The number is not prime");
	}
	else {
		printf("The number is prime");
	}
	return 0;
}
