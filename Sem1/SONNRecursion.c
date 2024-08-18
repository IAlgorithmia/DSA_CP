#include <stdio.h>
int SONN(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n + SONN(n-1);
	}
}
int main()
{
	int num;
	printf("Enter the desired number to which you want the sum of natural numbers : \n");
	scanf("%d", &num);
	printf("The sum of natural numbers upto %d is %d", num, SONN(num));
	return 0;
}
