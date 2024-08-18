#include <stdio.h>
struct spterm
{
	int row;
	int col;
	int val;
};
void addition(struct spterm sparse1[], struct spterm sparse2[], struct spterm sparse3[])
{
	int i = 1, j = 1, k = 1;
	while (i <= sparse1[0].val && j<= sparse2[0].val)
	{
		if (sparse1[i].row == sparse2[j].row && sparse1[i].col == sparse2[j].col)
		{
			if (sparse1[i].val + sparse2[j].val != 0)
			{
				sparse3[k].row = sparse1[i].row;
				sparse3[k].col = sparse1[i].col;
				sparse3[k].val = sparse1[i].val + sparse2[j].val;
				sparse3[0].val++;
			}
			i++;
			j++;
			k++;
		}
		else if(sparse1[i].row == sparse2[j].row && sparse1[i].col < sparse2[j].col)
		{
			sparse3[k].row = sparse1[i].row;
			sparse3[k].col = sparse1[i].col;
			sparse3[k].val = sparse1[i].val;
			i++;
			k++;
			sparse3[0].val++;
		}
		else if(sparse1[i].row == sparse2[j].row && sparse1[i].col > sparse2[j].col)
		{
			sparse3[k].row = sparse2[j].row;
			sparse3[k].col = sparse2[j].col;
			sparse3[k].val = sparse2[j].val;
			j++;
			k++;
			sparse3[0].val++;
		}
		else if(sparse1[i].row < sparse2[j].row)
		{
			sparse3[k].row = sparse1[i].row;
			sparse3[k].col = sparse1[i].col;
			sparse3[k].val = sparse1[i].val;
			i++;
			k++;
			sparse3[0].val++;
		}
		else
		{
			sparse3[k].row = sparse2[j].row;
			sparse3[k].col = sparse2[j].col;
			sparse3[k].val = sparse2[j].val;
			j++;
			k++;
			sparse3[0].val++;
		}
	}
	while (i <= sparse1[0].val)
	{
		sparse3[k].row = sparse1[i].row;
		sparse3[k].col = sparse1[i].col;
		sparse3[k].val = sparse1[i].val;
		i++;
		k++;
		sparse3[0].val++;
	}
	while (j <= sparse2[0].val)
	{
		sparse3[k].row = sparse2[j].row;
		sparse3[k].col = sparse2[j].col;
		sparse3[k].val = sparse2[j].val;
		j++;
		k++;
		sparse3[0].val++;
	}
}
int main()
{
	printf("Enter the number of rows and columns of both the matrices : \n");
	int rows, columns;
	scanf("%d %d", &rows, &columns);
	struct spterm sparse1[100];
	struct spterm sparse2[100];
	sparse1[0].row = rows;
	sparse1[0].col = columns;
	sparse1[0].val = 0;
	sparse2[0].row = rows;
	sparse2[0].col = columns;
	sparse2[0].val = 0;
	printf("Enter the elements for matrix 1 - \n");
	int i, j, value;
	int index = 1;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			scanf("%d", &value);
			if (value != 0)
			{
				sparse1[index].row = i;
				sparse1[index].col = j;
				sparse1[index].val = value;
				index++;
				sparse1[0].val++;
			}
		}
	}
	printf("Enter the elements for matrix 2 - \n");
	index = 1;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			scanf("%d", &value);
			if (value != 0)
			{
				sparse2[index].row = i;
				sparse2[index].col = j;
				sparse2[index].val = value;
				index++;
				sparse2[0].val++;
			}
		}
	}
	struct spterm sparse3[100];
	sparse3[0].row = rows;
	sparse3[0].col = columns;
	sparse3[0].val = 0;
	addition(sparse1, sparse2, sparse3);
	printf("The first matrix is : \n");
	index = 1;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (sparse1[index].row == i && sparse1[index].col == j)
			{
				printf("%2d ", sparse1[index].val);
				index++;
			}
			else
			{
				printf("%2d ", 0);
			}
		}
		printf("\n");
	}
	printf("The second matrix is : \n");
	index = 1;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (sparse2[index].row == i && sparse2[index].col == j)
			{
				printf("%2d ", sparse2[index].val);
				index++;
			}
			else
			{
				printf("%2d ", 0);
			}
		}
		printf("\n");
	}
	printf("The resultant addition matrix is : \n");
	index = 1;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (sparse3[index].row == i && sparse3[index].col == j)
			{
				printf("%2d ", sparse3[index].val);
				index++;
			}
			else
			{
				printf("%2d ", 0);
			}
		}
		printf("\n");
	}
}
