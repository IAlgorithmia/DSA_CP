#include <stdio.h>
int main(int argc, char const *argv[])
{
    // A five digit number is entered by the user. Display the sum of its digits
    int a, num, sum = 0;
    printf("Enter an integral number (within the range of integers) : ");scanf("%d", &num);
    while (num!=0){
        a = num % 10;
        sum = sum + a;
        num = num / 10;
    }
    printf("The sum of the digits is %d", sum);
    return 0;
}
