#include <stdio.h>
int main(){
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
    int sum = 0;
    for (int i = 0; i <= rows - 1; i++)
    {
        for (int j = 0; j <= columns - 1; j++)
        {
            sum += mat[i][j];
        }
    }
    float avg = (float)sum / (rows * columns);
    printf("The sum of the elements of the matrix is %.3f", avg);
    return 0;
}