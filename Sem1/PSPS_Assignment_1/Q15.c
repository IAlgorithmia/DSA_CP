#include <stdio.h>
int main()
{
    int dim;
    printf("Enter the desired number of rows and columns of the array : \n");
    scanf("%d", &dim);
    int mat[dim][dim];
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            printf("Enter the element at index [%d,%d] for 1st Matrix\n", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    int ansmat[dim][dim];
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            ansmat[i][j] = mat[j][i];
        }
    }
    int decider = 0;
    int a = 1;
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            if (ansmat[i][j] == mat[i][j])
            {
                decider++;
            }
        }
    }
    if (decider == (dim * dim))
    {
        printf("The matrix is symmetric");
        a = 0;
    }
    decider = 0;
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            if (ansmat[i][j] == -mat[i][j])
            {
                decider--;
            }
        }
    }
    if (decider == -(dim * dim))
    {
        printf("The matrix is skew-symmetric");
        a = 0;
    }
    if (a == 1)
    {
        printf("The matrix is neither symmetric nor skew-symmetric");
    }
    return 0;
}