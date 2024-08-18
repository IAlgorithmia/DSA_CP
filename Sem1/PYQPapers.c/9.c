#include <stdio.h>
int main()
{
    int rows, columns;
    printf("Enter the desired number of rows and columns of the array : \n");
    scanf("%d %d", &rows, &columns);
    int mat[rows][columns];
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            printf("Element [%d,%d] : \n", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
        }
    }
    return 0;
}