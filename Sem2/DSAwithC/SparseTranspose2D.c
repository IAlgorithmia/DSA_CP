#include <stdio.h>
int main()
{
    // Since my 2d arrays sucks, this program will be non modular :(
    int i, j, rows, columns;
    printf("Enter the desired number of rows of the array : \n");
    scanf("%d", &rows);
    printf("Enter the desired number of columns of the array : \n");
    scanf("%d", &columns);
    int smatrix[100][3];
    int input, var;
    var = 0;
    smatrix[var][0] = rows;
    smatrix[var][1] = columns;
    smatrix[var][2] = 0;
    printf("Enter the values : \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            scanf("%d", &input);
            if (input != 0)
            {
                smatrix[var + 1][0] = i;
                smatrix[var + 1][1] = j;
                smatrix[var + 1][2] = input;
                smatrix[0][2]++;
                var++;
            }
        }
    }
    var = 1;
    printf("The original matrix is : \n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            if (i == smatrix[var][0] && j == smatrix[var][1])
            {
                printf("%d ", smatrix[var][2]);
                var++;
            }
            else
            {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
    var = 1; 
    int var2;
    int stmatrix[smatrix[0][2] + 1][3];
    stmatrix[0][0] = columns;
    stmatrix[0][1] = rows;
    stmatrix[0][2] = smatrix[0][2];
    for (i = 0; i < columns; i++)
    {
        for (j = 1; j < smatrix[0][2] + 1; j++)
        {
            if (smatrix[j][1] == i)
            {
                stmatrix[var][0] = smatrix[j][1];
                stmatrix[var][1] = smatrix[j][0];
                stmatrix[var][2] = smatrix[j][2];
                var++;
            }
        }
    }
    var = 1;
    printf("The transposed matrix is : \n");
    for (i = 0; i < columns; i++)
    {
        for (j = 0; j < rows; j++)
        {
            if (i == stmatrix[var][0] && j == stmatrix[var][1])
            {
                printf("%d ", stmatrix[var][2]);
                var++;
            }
            else
            {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
    return 0;
}