#include <stdio.h>
int main(){
	int j, i, num, fac = 1;
	float sum; sum=0;
	printf("Enter the number");
	scanf("%d", &num);
	for (i=1;i<=num;i++){
		for (j=1;j<=i;j++){
			fac = fac * j;
		} 
		sum = sum + (i/fac);
	}
	printf("The factorial is %f", sum);
	return 0;
}
