#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    printf("Enter a string : \n");
    char string[1000];
    gets(string);
    char ans[1000];
    int j = 0;
    int length = strlen(string);
    for (int i = 0; i <= length - 1; i++)
    {
        if (isalpha(string[i]) == 1 || isalpha(string[i]) == 2)
        {
            ans[j] = string[i];
            j++;
        }
    }
    ans[j] = '\0';
    puts(ans);
    return 0;
}