#include <stdio.h>
int main()
{
	// Polynomial Addition, consecutive elements, Using Arrays
	printf("Enter the highest power of the polynomial 1 : \n");
	int degree1;
	scanf("%d", &degree1);
	int i;
	int arr1[degree1 + 1];
	printf("Enter the coeffecients of consecutive terms for polynomial 1 : \n");
	for (i = 0; i <= degree1; i++)
	{
		scanf("%d", &arr1[i]);
	}
	printf("\n");
	printf("Enter the highest power of the polynomial 2 : \n");
	int degree2;
	scanf("%d", &degree2);
	int arr2[degree2 + 1];
	printf("Enter the coeffecients of consecutive terms for polynomial 2 : \n");
	for (i = 0; i <= degree2; i++)
	{
		scanf("%d", &arr2[i]); 
	}
	printf("\nThe first polynomial is :\n");
	for (i = degree1; i >= 0; i--)
	{
		if (arr1[degree1 - i] != 0)
		{
			printf("%dx^%d", arr1[degree1 - i], i);
		}
		if (i != 0)
		{
			if (arr1[degree1 - i + 1] > 0)
			{
				printf("+");
			}
		}
	}
	printf("\nThe second polynomial is :\n");
	for (i = degree2; i >= 0; i--)
	{
		if (arr2[degree2 - i] != 0)
		{
			printf("%dx^%d", arr2[degree2 - i], i);
		}
		if (i != 0)
		{
			if (arr2[degree2 - i + 1] > 0)
			{
				printf("+");
			}
		}
	}
	int max = ((degree1 > degree2) ? degree1 : degree2);
	int arr3[max + 1];
	i = 0;
	int j = 0, k = 0, var, temp;
	temp = max;
	for (var = max; var >= 0; var--)
	{
		if ((degree1 - i) == temp && (degree2 - j) == temp)
		{
			arr3[k] = arr1[i] + arr2[j];
			i++;
			k++;
			j++;
			temp--;
		}
		else if ((degree1 - i) == temp)
		{
			arr3[k] = arr1[i];
			i++;
			k++;
			temp--;
		}
		else
		{
			arr3[k] = arr2[j];
			k++;
			j++;
			temp--;
		}
	}
	printf("\nThe added polynomial is :\n");
	for (i = max; i >= 0; i--)
	{
		if (arr3[max - i] != 0)
		{
			printf("%dx^%d", arr3[max - i], i);
		}
		if (i != 0)
		{
			if (arr3[max - i + 1] > 0)
			{
				printf("+");
			}
		}
	}
}