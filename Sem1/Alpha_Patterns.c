#include <stdio.h>
int main()
{
    // Pattern 1
    int i, j;
    for (i = 1; i <= 7; i++)
    {
        for (j = 1; j <= 8 - i; j++)
        {
            printf("%c", j + 64);
        }
        if (i == 1)
        {
            for (j = 6; j >= 1; j--)
            {
                printf("%c", 64 + j);
            }
        }
        else
        {
            for (j = 1; j <= (2 * i - 3); j++)
            {
                printf(" ");
            }
            for (j = 8 - i; j >= 1; j--)
            {
                printf("%c", 64 + j);
            }
        }
        printf("\n");
    }
    // Pattern 2
    int num;
    printf("Enter the number of rows you want to see :\n");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%c ", 64 + i);
        }
        printf("\n");
    }

    // Pattern 3
    int num;
    printf("Enter the number of rows you want to see :\n");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num - i + 1; j++)
        {
            printf("%c ", 64 + j);
        }
        printf("\n");
    }

    // Pattern 4
    int num;
    printf("Enter the number of rows you want to see :\n");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            printf("%c", 64 + j);
        }
        for (int j = 2; j <= i; j++)
        {
            printf("%c", 64 + j);
        }
        printf("\n");
    }
    // Pattern 5
    int num, x = 1;
    printf("Enter the number of rows you want to see :\n");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (x % 2 != 0)
            {
                printf("%c", 64 + x);
                x++;
            }
            else
            {
                printf("%c", 96 + x);
                x++;
            }
        }
        printf("\n");
    }
    // Pattern 6
    int num, x = 1;
    printf("Enter the number of rows you want to see :\n");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
            return 0;
        // Pattern 7
        int i, j, k;
        printf("ABCDEFGFEDCBA\n"); //Ye badtameezi hai, aise mat karna, i ke liye alag case banake karna
        for (i = 1; i <= 6; i++)
        {
            for (j = 1; j <= 7 - i; j++)
            {
                printf("%c", 64 + j);
            }
            for (k = 1; k <= (2 * (i)-1); k++)
            {
                printf(" ");
            }
            for (j = 7 - i; j >= 1; j--)
            {
                printf("%c", 64 + j);
            }
            printf("\n");
        }
    }