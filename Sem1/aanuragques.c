#include <stdio.h>
int main()
{
    int num;
    printf("Enter the number to which you want it to go : \n");
    scanf("%d", &num);
    int min(int a, int b)
    {
        if (a > b)
        {
            return b;
        }
        else if (b > a)
        {
            return a;
        }
    }
    for (int i = 1; i <= 2 * num - 1; i++)
    {
        for (int j = 1; j <= 2 * num - 1; j++)
        {
            if (i <= num && j <= num)
            {
                printf("%d", min(i, j));
            }
            else if (i > num && j > num)
            {
                printf("%d", min(2 * num - i, 2 * num - j));
            }
            else if (i > num)
            {
                printf("%d", min(2 * num - i, j));
            }
            else if (j > num)
            {
                printf("%d", min(i, 2 * num - j));
            }
        }
        printf("\n");
    }
}