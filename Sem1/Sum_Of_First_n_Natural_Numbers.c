#include <stdio.h>
int main(){
	int num;
	printf("Enter how many of the first natural numbers' sum you want to see : \n");
	scanf("%d", &num);
	int count = 1;
	int sum = 0;
	int i;
	for (i=1; i<= num; i++){
		sum = sum + count;
		count++;
	}
	printf("The sum of the first %d natural numbers is %d\n", num, sum);
}
