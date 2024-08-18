#include <stdio.h>
#include <string.h>
int main()
{
    printf("Enter the name of the first friend : \n");
    char fr1[55];
    gets(fr1);
    printf("Enter the name of the second friend : \n");
    char fr2[55];
    gets(fr2);
    char mids[] = " is a friend of ";
    strcat(mids, fr2);
    strcat(fr1, mids);
    puts(fr1);
    return 0;
}