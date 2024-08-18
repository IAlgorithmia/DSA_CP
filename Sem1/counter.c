#include <stdio.h>
#include <string.h>
void counter(char str[])
{
    int words = 1;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
        {
            words++;
        }
    }
    printf("Number of words : %d\nNumber of characters : %d", words, len);
}
int main()
{
    printf("Enter the string (<1000 characters in 1 line). Enter 0 in a single line to complete the string\n");
    char string[] = "";
    int lines = 0;
    char str[1000];
    while (1)
    {
        printf("The value of lines is %d\n", lines);
        lines = lines + 1;
        gets(str);
        strcat(string, str);
        if (strcmp(str, "0") == 0)
        {
            break;
        }
    }
    printf("Lines are %d\n", lines);
    puts(string);
    printf("Number of lines : %d\n", lines);
    counter(string);
    return 0;
}