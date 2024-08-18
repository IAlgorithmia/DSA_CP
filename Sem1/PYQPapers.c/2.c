#include <stdio.h>
int main()
{
    int i, j, k, a;
    int num;
    printf("Enter the number : \n");
    scanf("%d", &num);
    for (a = 1; a <= num; a++)
    {
        printf("%d", a);
    }
    for (a = num - 1; a >= 1; a--)
    {
        printf("%d", a);
    }
    printf("\n");
    for (i = 1; i <= num - 1; i++)
    {
        for (j = 1; j <= num - i; j++)
        {
            printf("%d", j);
        }
        for (k = 1; k <= 2 * (i) - 1; k++)
        {
            printf(" ");
        }
        for (j = num - i; j >= 1; j--)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}