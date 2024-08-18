#include <stdio.h>
int fac(int n)
{
	int i;
	int ans = 1;
	for (i=1;i<=n;i++){
		ans = ans * i;
	}
	return ans;
}
int main()
{
	int num;
	printf("Enter the number whose factorial you wich to know : \n");
	scanf("%d", &num);
	printf("The factorial of %d is %d", num, fac(num));
	return 0;
}
