#include <stdio.h>
#include <string.h>
int main()
{
    char str1[] = "Vaibhav";
    char str2[] = " Sharma ";
    char str3[500];
    printf("The strcmp for S1 and S2 is returned %d", strcmp(str1, str2));
    printf("The concatenated string is : \n");
    puts(strcat(str1, str2));
    printf("The length of string 1 is : %d\n", strlen(str1));
    printf("The length of string 2 is : %d\n", strlen(str2));
    printf("The reverse of string 1 is : %s\n", strrev(str1));
    printf("The reverse of string 2 is : %s\n", strrev(str2));
    strcpy(str3, strcat(str1, str2));
    puts(str3);
    // str3 = strcat(str1, str2) This is utter BS because we CANNOT assign value to an ARRAY (str3) in this manner
    return 0;
}