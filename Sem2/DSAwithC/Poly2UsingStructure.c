#include <stdio.h>
struct poly
{
	int expo;
	int coeff;
};
int main()
{
	// Polynomial Addition, termwise, Using Arrays
	printf("Enter the number of terms in 1st polynomial : \n");
	int terms1;
	scanf("%d", &terms1);
	int i;
	struct poly poly1[terms1];
	printf("Enter the coeffecients : \n");
	for (i = 0; i <= terms1 - 1; i++)
	{
		scanf("%d", &poly1[i].coeff);
		poly1[i].expo = terms1 - 1 - i;
	}
	printf("Enter the number of terms in 2nd polynomial : \n");
	int terms2;
	scanf("%d", &terms2);
	struct poly poly2[terms2];
	printf("Enter the coeffecients : \n");
	for (i = 0; i <= terms2 - 1; i++)
	{
		scanf("%d", &poly2[i].coeff);
		poly2[i].expo = terms2 - 1 - i;
	}
	printf("The first polynomial is : \n");
	for (i = 0; i <= terms1 - 1; i++)
	{
		if (poly1[i].coeff != 0)
		{
			printf("%dx^(%d)",poly1[i].coeff, terms1 - 1 - i);
		}
		if (poly1[i + 1].coeff > 0 && terms1 - 1 - i != 0)
		{
			printf("+");
		}
	}
	printf("\nThe second polynomial is : \n");
	for (i = 0; i <= terms2 - 1; i++)
	{
		if (poly2[i].coeff != 0)
		{
			printf("%dx^(%d)",poly2[i].coeff, terms2 - 1 - i);
		}
		if (poly2[i + 1].coeff > 0 && terms2 - 1 - i != 0)
		{
			printf("+");
		}
	}
	int max = (terms1 > terms2 ? terms1 : terms2);
	int x = 0, y = 0, z = 0;
	struct poly poly3[max];
	for (i = 0; i <= max - 1; i++)
	{
		if (poly1[x].expo == poly2[y].expo)
		{
			poly3[z].expo == poly1[x].expo;
			poly3[z].coeff = poly1[x].coeff + poly2[y].coeff;
			x++; y++; z++;
		}
		else if (poly1[x].expo > poly2[y].expo)
		{
			poly3[z].expo == poly1[x].expo;
			poly3[z].coeff = poly1[x].coeff;
			x++; z++;
		}
		else
		{
			poly3[z].expo == poly2[y].expo;
			poly3[z].coeff = poly2[y].coeff;
			y++; z++;
		}
	}
	printf("\nThe resultant polynomial is : \n");
	for (i = 0; i <= max - 1; i++)
	{
		if (poly3[i].coeff != 0)
		{
			printf("%dx^(%d)",poly3[i].coeff, max - i - 1);
		}
		if (poly3[i + 1].coeff > 0 && max  - 1 - i != 0)
		{
			printf("+");
		}
	}
}
