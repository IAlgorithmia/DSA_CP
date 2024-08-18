#include <stdio.h>
int fibo(int n)
{
	if (n == 1)
	{
		return  0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else 
	{
		return fibo(n-1) + fibo(n-2);
	}
}
int main()
{
	int num;
	printf("Enter the desired element number : \n");
	scanf("%d", &num);
	printf("The element %d of fibonacci series is %d", num, fibo(num));
	return 0;
}
