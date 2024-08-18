#include <stdio.h>
int gcd(int x, int y)
{
    int ans;
    int min = (x < y) ? x : y;
    for (int i = 1; i <= min; i++)
    {
        if (x % i == 0 && y % i == 0)
        {
            ans = i;
        }
    }
    return ans;
}
int eucldgcd(int a, int b)
{
    // Assuming b > a
    // Google euclid's algorithm first
    if (b % a == 0)
    {
        return a;
    }
    else
    {
        return eucldgcd(b % a, a);
    }
}
int lcm(int x, int y)
{
    // Method 1
    int max;
    max = (x > y) ? x : y;
    while (1)
    {
        if (max % x == 0 && max % y == 0)
        {
            return max;
        }
        max++;
    }
    // Method 2
    return (x * y / gcd(x, y));
}
int main()
{
    printf("Enter the first number : \n");
    int num1;
    scanf("%d", &num1);
    printf("Enter the second number : \n");
    int num2;
    scanf("%d", &num2);
    printf("Their lcm is %d\n", lcm(num1, num2));
    printf("Their gcd is %d", gcd(num1, num2));
    printf("Their gcd by euclid's algorithm is %d", eucldgcd(num1, num2));
}