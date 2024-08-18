#include <stdio.h>
#include <string.h>
void strdel(char string[], int start, int del) // "Hey there Vaibhav!", 5, 3
{
    int length = strlen(string);
    for (int i = 0; i <= start  - 1; i++)
    {
        printf("%c", string[i]);   
    }
    for (int i = start + del; i <= length - 1; i++)
    {
        printf("%c", string[i]);   
    }
}
int main()
{
    printf("Enter the string (<1000 characters) : \n");
    char str[1000];
    gets(str);
    printf("Enter how many characters you want deleted and from which index : \n");
    int s1; int s2;
    scanf("%d %d", &s1, &s2);
    printf("The resultant string is :\n");
    strdel(str, s2, s1);
    return 0;
}