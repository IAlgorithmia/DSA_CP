#include <stdio.h>
int main()
{
    char array[50];
    printf("Enter your name : \n");
    scanf("%[^\n]s", array);
    printf("The name is %s", array);
    return 0;
}