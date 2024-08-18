#include <stdio.h>
int xstrlen(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
char xstrrev(char *str[])
{
    int len = xstrlen(str);
    for (int i = 0; i <= (len / 2) - 1; i++)
    {
        swap(str[i], str[len - 1 - i]);
    }
}
// char xstrcat(char str1[], char str2[])
// {
//     int len1 = xstrlen(str1);
//     int len2 = xstrlen(str2);
//     char str[len1 + len2 + 1];
//     for (int i = 0; i <= len1 - 1; i++)
//     {
//         str[i] = str1[i];
//     }
//     for (int i = len1; i <= len1 + len2 - 1; i++)
//     {
//         str[i] = str2[i - len1];
//     }
//     str[len1 + len2] = '\0';
//     return str;
// }
// char xstrcpy(char str1[], char str2[])
// {
//     //Str1 should be defined size should already be defined, equal to the size of the second string
//     int len = xstrlen(str2);
//     for (int i = 0; i <= len - 1; i++)
//     {
//         str1[i] = str2[i];
//     }
//     str1[len] = '\0';
//     return str1;
// }
int main()
{
    char string1[] = "Vaibhav ";
    char string2[] = "Sharma";
    char stringcpy[7];
    printf("Length of string 1 is : %d, Length of string 2 is : %d\n", xstrlen(string1), xstrlen(string2));
    xstrrev(string1);
    printf("The reversed string is %s\n", string1);
    // printf("The copied string is %s\n", xstrcpy(stringcpy, string2));
    // printf("the cponcatenated string is %s\n", xstrcat(string1, string2));
}