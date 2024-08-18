#include <stdio.h>
int main()
{
	printf("Enter the desired number of rows/columns of the square matrix : \n"); int x; scanf("%d", &x);
	int arr[x][x], arr1[x][x];
	int i, j;
	for (i = 0; i <= x - 1; i++)
	{
		for (j = 0; j <= x - 1; j++)
		{
			printf("Enter element for (%d, %d) : ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i <= x - 1; i++)
	{
		for (j = 0; j <= x - 1; j++)
		{
			arr1[j][i] = arr[i][j];
		}
	}
	printf("First martix : \n");
	for (i = 0; i <= x - 1; i++)
	{
		for (j = 0; j <= x - 1; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("Second martix : \n");
	for (i = 0; i <= x - 1; i++)
	{
		for (j = 0; j <= x - 1; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	int check = 1;
	for (i = 0; i <= x - 1; i++)
	{
		for (j = 0; j <= x - 1; j++)
		{
			if (arr1[i][j] != arr[i][j])
			{
				check = 0;
			}
		}
	}
	if (check == 1)
	{
		printf("The matrix is symmetric!");
	}
	else
	{
		printf("The matrix is not symmetric!");
	}
}
