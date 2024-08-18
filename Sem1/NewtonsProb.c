#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i <= num-1; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans = 999, sum1, sum2, l, s;
    for (int i = 0; i <= num - 1; i++)
    {
        sum1 = 0;
        sum2 = 0;
        for (int j = 0; j <= i; j++)
        {
            sum1 += arr[j];
        }
        for (int j = i + 1; j <= num - 1; j++)
        {
            sum2 += arr[j];
        }
        l = (sum1 > sum2) ? sum1 : sum2;
        s = (sum1 < sum2) ? sum1 : sum2;
        if (ans > (l - s))
        {
            ans = l - s;
        }
    }
    printf("%d", ans);
    return 0;
}