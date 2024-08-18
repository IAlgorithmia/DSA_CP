#include <stdio.h>
int main(){
	int sumdig = 0, num, dig=0;
	printf("Enter the number of your choice : \n");
	scanf("%d", &num);
	while (num != 0){
		dig = num % 10;
		num = num / 10;
		sumdig = sumdig + dig;
	}
	printf("The sum of digits is %d", sumdig);
	return 0;
}
