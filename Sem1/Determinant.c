#include <stdio.h>
#define MAX 100

int determinant(int n, int mat[MAX][MAX]);

int main()
{
    int n, i, j;
    int mat[MAX][MAX];
    printf("Enter the dimension of the square matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    int det = determinant(n, mat);
    printf("The determinant of the matrix is: %d\n", det);
    return 0;
}

int determinant(int n, int mat[MAX][MAX])
{
    int i, j, k;
    int sub_mat[MAX][MAX];
    int det = 0;
    if (n == 1)
        return mat[0][0];
    else if (n == 2)
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    else
    {
        for (k = 0; k < n; k++)
        {
            int sub_i, sub_j;
            for (i = 1; i < n; i++)
            {
                sub_j = 0;
                for (j = 0; j < n; j++)
                {
                    if (j == k)
                        continue;
                    sub_mat[sub_i][sub_j] = mat[i][j];
                    sub_j++;
                }
                sub_i++;
            }
            det = det + mat[0][k] * determinant(n - 1, sub_mat) * ((k % 2 == 0) ? 1 : -1);
        }
        return det;
    }
}
