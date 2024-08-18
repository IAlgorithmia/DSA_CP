#include <stdio.h>
int fac(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return n*fac(n-1);
	}
}
int main()
{
	int num;
	printf("Enter the desired number : \n");
	scanf("%d", &num);
	printf("The factorial of the given number is %d", fac(num));
	return 0;
}
