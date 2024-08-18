#include <stdio.h>
#include <string.h>
int main()
{
    printf("Enter the string\n");
    char string[500];
    char ans[] = "";
    gets(string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            strncat(ans, &string[i], 1);
        }
    }
    puts(ans);
    return 0;
}