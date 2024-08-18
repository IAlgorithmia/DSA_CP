#include <stdio.h>
int main(){
	int num, i, fac = 1;
	printf("Enter the number of your choice : \n");
	scanf("%d", &num);
	for (i=1; i<=num;i++){
		fac = fac * i;
	}
	printf("The factorial is %d", fac);
	return 0;
}
