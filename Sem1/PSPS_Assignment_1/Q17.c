#include <stdio.h>
int main()
{
    int rows, columns;
    printf("Enter the desired rows of the arrays : \n");
    scanf("%d", &rows);
    printf("Enter the desired columns of the arrays : \n");
    scanf("%d", &columns);
    int mat1[rows][columns];
    int mat2[rows][columns];
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            printf("Enter the element at index [%d,%d] for 1st Matrix\n", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            printf("Enter the element at index [%d,%d] for 2nd Matrix\n", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("The difference of the matrices is : \n");
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            printf("%2d ", mat1[i][j] - mat2[i][j]);
        }
        printf("\n");
    }
}