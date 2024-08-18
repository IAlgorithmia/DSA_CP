#include <stdio.h>
int fac(int r)
{
    int ans = 1;
    for (int x = 1; x <= r; x++)
    {
        ans = ans * x;
    }
    return ans;
}
int ncr(int n, int r)
{
    return fac(n) / ((fac(r)) * (fac(n - r)));
}
int main()
{
    int num;
    printf("Enter the number of rows you want to see : \n");
    scanf("%d", &num);
    // Method 1 - Using Functions
    int i, j, k;
    for (i = 0; i <= num - 1; i++)
    {
        for (k = 1; k <= (num - i); k++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("%d ", ncr(i, j));
        }

        printf("\n");
    }
    // Method 2 - Without Using Functions
    int num, i, j, c, k;
    printf("Enter the number of rows you want to see : \n");
    scanf("%d", &num);
    for (i = 0; i <= num - 1; i++)
    {
        for (k = 1; k <= num - i; k++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0)
            {
                c = 1;
            }
            else
            {
                c = c * (i - j + 1) / j; // Using the (n-r+1)/r method
            }
            printf("%2d", c);
        }
        printf("\n");
    }
    return 0;
}