#include <stdio.h>
int fac(int x)
{
    int ans = 1;
    for (int i = 1; i <= x; i++)
    {
        ans = ans * i;
    }
    return ans;
}
int ncr(int n, int r)
{
    return (fac(n) / (fac(r) * fac(n - r)));
}
int main()
{
    printf("Enter how many lines you want to see : \n");
    int num;
    scanf("%d", &num);
    for (int i = 0; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("%d ", ncr(i, k));
        }
        printf("\n");
    }
    return 0;
}