#include <stdio.h>

int main()
{
    char arr[] = "abcd";
    char *p = arr;

    printf("%c\t", ++*p);
    printf("%c\t", *p++);
    printf("%c\t", (*p)++);
    printf("%c\n", *p);

    return 0;
}