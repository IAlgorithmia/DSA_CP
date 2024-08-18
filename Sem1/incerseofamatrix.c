#include <stdio.h>
int main()
{
    int dim;
    printf("Enter the desired number of rows and columns of the array : \n");
    scanf("%d", &dim);
    int mat[dim][dim];
    printf("Enter the matrix : \n");
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }  
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}