#include <stdio.h>
int main()
{
    int num;
    printf("Enter the number of rows you want to see : \n");
    scanf("%d", &num);
    int i, j, k, x = 1;
    for (i = 1; i <= num; i++)
    {
        for (k = 1; k <= (num - i); k++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("%d ", x);
            x++;
        }
        printf("\n");
    }
    return 0;
}