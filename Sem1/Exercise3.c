#include <stdio.h>
// #1 Recursive approach
// Recursive approach is slower as compared to loop
int fibo(int n)
{
    switch (n)
    {
    case 1:
        return 0;
        break;

    case 2:
        return 1;
        break;
    default:
        return (fibo(n - 1) + fibo(n - 2));
        break;
    }
}
// #2 Iterative approach
int fibo(int n)
{
    int a[n];
    a[0] = 0;
    a[1] = 1; 
    if (n > 2)
    {
        for (int i = 2; i <= (n-1); i++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
    }
    return a[n - 1];
}
int main()
{
    int n, dec = 1;
    while (dec)
    {
        printf("Enter which element of the fibonacci series that you wish to know :\n");
        scanf("%d", &n);
        printf("The term %d of the fibonacci series is %d\n\n", n, fibo(n));
        printf("Would you like to know another term? (Enter 0 for No, any other number for yes)\n");
        scanf("%d", &dec);
        if (dec == 0)
        {
            printf("Bye bye see ya\n");
        }
        else
        {
            printf("Sure! Here you go\n");
        }
    }
    return 0;
}
