#include <stdio.h>
int main()
{ // Q1 - Finding and Displaying Duplicates of items if present
    int num;
    printf("Enter the desired length of the array : \n");
    scanf("%d", &num);
    int a[num];
    int dupcount = 0;
    for (int i = 0; i <= num - 1; i++)
    {
        printf("Enter the element for index %d :\n", i);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= num - 2; i++)
    {
        for (int j = i + 1; j <= num - 1; j++)
        {
            if (a[i] != NULL && a[i] == a[j])
            {
                dupcount++;
                a[j] = NULL;
            }
        }
        if (a[i] != NULL && dupcount != 0)
        {
            printf("The element %d of index %d has %d duplicates\n", a[i], i, dupcount);
            dupcount = 0;
        }
    }

    // Q2 - Addition - Subtraction of 2D Arrays
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
    printf("The sum of the matrices is : \n");
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            printf("%2d ", mat1[i][j] + mat2[i][j]);
        }
        printf("\n");
    }
    // Q3 - Multiplication of two Arrays
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