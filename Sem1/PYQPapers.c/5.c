#include <stdio.h>
#include <string.h>
int main()
{
    char string[500];
    printf("Enter the string : \n");
    gets(string);
    int check = 1;
    int length = strlen(string);
    for (int i = 0; i <= length - 1; i++)
    {
        if (string[i] != string[length - 1- i])
        {
            check = 0;
        }
    }
    if (check == 1)
    {
        printf("It is a palindrome");
    }
    else
    {
        printf("It isn't palindrome");
    }
    return 0;
}