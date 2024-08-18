#include <stdio.h>
int main()
{
	int row, comm, col;
	printf("Enter the number of rows of 1st matrix you want to enter : \n");
	scanf("%d", &row);
	printf("Enter the number of columns of 1st and rows of 2nd you want to enter : \n");
	scanf("%d", &comm);
	printf("Enter the number of columns of 2nd matrix you want to enter : \n");
	scanf("%d", &col);
	int arr1[row][comm];
	int arr2[comm][col];
	int ans[row][col];
	int i, j, k;
	for (i = 0; i <= row - 1; i++)
	{
		for (j = 0; j <= comm - 1; j++)
		{
			printf("Enter the element at %d, %d of first matrix\n", i, j);
			scanf("%d", &arr1[i][j]);
		}
	}
	for (i = 0; i <= comm - 1; i++)
	{
		for (j = 0; j <= col - 1; j++)
		{
			printf("Enter the element at %d, %d of second matrix\n", i, j);
			scanf("%d", &arr2[i][j]);
		}
	}
	for (i = 0; i <= row - 1; i++)
	{
		for (j = 0; j <= col - 1; j++)
		{
			ans[i][j] = 0;
		}
	}
	for (i = 0; i <= row - 1; i++)
	{
		for (j = 0; j <= col - 1; j++)
		{
			for (k = 0; k <= comm - 1; k++)
			{
				ans[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	printf("The first matrix is : \n");
	for (i = 0; i <= row - 1; i++)
	{
		for (j = 0; j <= comm - 1; j++)
		{
			printf("%2d", arr1[i][j]);
		}
		printf("\n");
	}
	printf("The second matrix is : \n");
	for (i = 0; i <= comm - 1; i++)
	{
		for (j = 0; j <= col - 1; j++)
		{
			printf("%2d", arr2[i][j]);
		}
		printf("\n");
	}
	printf("The product matrix is : \n");
	for (i = 0; i <= row - 1; i++)
	{
		for (j = 0; j <= col - 1; j++)
		{
			printf("%3d", ans[i][j]);
		}
		printf("\n");
	}
}
