#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int num, revnum, i;revnum = 0;
    printf("Enter an integral number (within the range of integers) : ");scanf("%d", &num);
    while (num!=0){
        i = num % 10;
        revnum = i + (revnum*10);
        num = num/10;
    }
    printf("The reversed number is %d", revnum);
    return 0;
}
