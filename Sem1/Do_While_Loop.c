#include <stdio.h>
int main()
{
    int index, num;
    index = 1;
    printf("Enter the integral number : ");
    scanf("%d", &num);
    do
    {
        printf("%d ", index);
        index = index + 1;
    } while (index <= num);
    return 0;
}
