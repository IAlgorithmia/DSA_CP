#include <stdio.h>
int main()
{    
    // Method 1
    int num;
    printf("Enter the number of rows you want to see :\n");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % 2 != 0)
            {
                if (j % 2 != 0)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
            else
            {
                if (j % 2 != 0)
                {
                    printf("0");
                }
                else
                {
                    printf("1");
                }
            }
        }
        printf("\n");
    }

    // Method 2
    int r;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    for (int i = 1; i <= r; i++)
    {
        if (i % 2 != 0)
        {
            printf("1");
            for (int j = 1; j <= i / 2; j++)
            {
                printf("01");
            }
        }
        else
        {
            for (int k = 1; k <= i / 2; k++)
            {
                printf("01");
            }
        }
        printf("\n");
    }

    // Another Floyd's Triangle
    int num;
    printf("Enter the numeber of rows you want to see :\n");
    scanf("%d", &num);
    int i,j,x=1;
    for (i=1;i<=num;i++){
        for (j=1;j<=i;j++){
            printf("%d ",x);
            x++;
        }
        printf("\n");
    }
    return 0;
}