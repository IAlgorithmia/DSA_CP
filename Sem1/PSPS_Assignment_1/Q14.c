#include <stdio.h>
int main(){
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
    int sum = 0;
    for (int i = 0; i <= dim - 1; i++)
    {
        sum += mat[i][i];
    }
    printf("The sum of the diagonal elements is %d", sum);
    return 0;
}