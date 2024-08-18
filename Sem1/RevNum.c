#include <stdio.h>
int main(){
	int num, dig, revnum = 0;
	printf("Enter the number of your choice : \n");
	scanf("%d", &num);
	while(num != 0){
		dig = num % 10;
		num = num/10;
		revnum = revnum*10 + dig;
	}
	printf("The reversed number is %d", revnum);
	return 0;
}
