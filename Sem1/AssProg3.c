#include <stdio.h>
int main(int argc, char const *argv[])
{
    int year;
    printf("Enter the year you want to check : ");scanf("%d", &year);
    if ((year%400 == 0) || ((year%100!=0) && (year%4==0))){
        printf("The year %d is a leap year", year);
    }
    else {
        printf("Naah re naa");
    }
    return 0;
}