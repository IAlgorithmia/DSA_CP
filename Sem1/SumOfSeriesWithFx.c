#include <stdio.h>
int fac(num){
	int i, fc = 1;
	for (i=1; i<=num;i++){
		fc = fc * i;
	}
	return fc;
}
int main(){
	int i, num;
	float sum = 0;
	printf("Enter the number of your choice : \n");
	scanf("%d", &num);
	for (i=1; i<=num; i++){
		printf("%d is the factorial\n", fac(i));
		sum = sum + ((float)i/(fac(i)));
	}
	printf("The sum is %.3f", sum);
}
