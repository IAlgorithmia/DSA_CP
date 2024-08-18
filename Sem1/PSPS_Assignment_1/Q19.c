#include <stdio.h>
int main()
{
    int rows, columns;
    printf("Enter the desired number of rows of the array : \n");
    scanf("%d", &rows);
    printf("Enter the desired number of columns of the array : \n");
    scanf("%d", &columns);
    int mat[rows][columns];
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            printf("Enter the element at index [%d,%d] for 1st Matrix\n", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    int ansmat[columns][rows];
    for (int i = 0; i <= columns - 1; i++)
    {
        for (int j = 0; j <= rows - 1; j++)
        {
            ansmat[i][j] = mat[j][i];
        }
    }
    printf("The transpose of the matrix is : \n");
    for (int i = 0; i <= columns - 1; i++)
    {
        for (int j = 0; j <= rows - 1; j++)
        {
            printf("%3d",ansmat[i][j]);
        }
        printf("\n");
    }
    return 0;
}