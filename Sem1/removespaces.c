#include <stdio.h>
#include <string.h>
int main()
{
    printf("Enter the string\n");
    char str[500];
    char nstr[500];
    int i = 0, j=0 ;
    gets(str);
    while(str[i]!='\0'){
        if(str[i]==' ')
            nstr[j]=str[++i];
        else
        nstr[j]=str[i];
        i++;
        j++;
    }
    nstr[j]='\0';
    printf("%s", nstr);
    return 0;
}