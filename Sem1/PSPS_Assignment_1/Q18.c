#include <stdio.h>
int main()
{
    int rows, cr, columns;
    printf("Enter the number of desired rows of the 1st array : \n");
    scanf("%d", &rows);
    printf("Enter the number of desired columns of 1st array and rows of 2nd array : \n");
    scanf("%d", &cr);
    printf("Enter the number of desired columns of the 2nd array : \n");
    scanf("%d", &columns);
    int mat1[rows][cr];
    int mat2[cr][columns];
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= cr - 1; j++)
        {
            printf("Enter the element at index [%d,%d] for %dX%d order 1st Matrix\n", i, j, rows, cr);
            scanf("%d", &mat1[i][j]);
        }
    }
    for (int i = 0; i <= cr - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            printf("Enter the element at index [%d,%d] for %dX%d order 2nd Matrix\n", i, j, cr, columns);
            scanf("%d", &mat2[i][j]);
        }
    }
    int ans[rows][columns];
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            ans[i][j] = 0;
        }
    }
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            int sum = 0;
            for (int k = 0; k <= cr - 1; k++)
            {
                sum += mat1[i][k] * mat2[k][j]; // The most important line of the entire code !!!!!
            }
            ans[i][j] += sum;
        }
    }
    // 3 nested loops lage hain, one for row, another for columns in each row, another for multiple multiplications for each 
    // element of the resultant matrix
    printf("The product matrix is : \n");
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            printf("%4d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}