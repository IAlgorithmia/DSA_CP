#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    printf("Enter the string\n");
    scanf("%[^~]", str);
    puts(str);
    return 0;
}