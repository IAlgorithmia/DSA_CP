#include <stdio.h>
int main()
{
    int n, m, s;
    printf("Enter the number of students, candies and the starting chair : \n");
    scanf("%d %d %d", &n, &m, &s);
    int ans = s + m - 1;
    while (ans > n)
    {
        ans = ans - n;
    }
    printf("The poor fellow has seat number : %d", ans);
    return 0;
}