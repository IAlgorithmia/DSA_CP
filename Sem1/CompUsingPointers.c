#include <stdio.h>
int max(int *a, int *b, int *c)
{
	if (*a > *b)
	{
		if (*a > *c)
		{
			printf("The greatest number is %d", *a);
		}
		else
		{
			printf("The greatest number is %d", *c);
		}
	}
	else
	{
		if (*b > *c)
		{
			printf("The greatest number is %d", *b);
		}
		else
		{
			printf("The greatest number is %d", *c);
		}
	}
}
int main()
{
	int x, y, z;
	printf("Enter three numbers : \n");
	scanf("%d %d %d", &x, &y, &z);
	max(&x, &y, &z);
}
