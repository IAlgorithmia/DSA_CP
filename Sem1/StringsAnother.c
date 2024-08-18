#include <stdio.h>
int main()
{
    char str[] = "Vaibhav Sharma";
    char *ptr = str;
    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
}