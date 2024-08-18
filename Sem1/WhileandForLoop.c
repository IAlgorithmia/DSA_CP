#include <stdio.h>
int main()
{
    int a, j, i=0;
    printf("Enter the integral number to which you want the count: ");
    scanf("%d", &a);
    while (i<=a)
    {
        printf("%d\n", i);i++;
    }
    printf("\n");
    for ( i = 0, j=0; i <= a; i++) 
    //Multiple variables can be declared in the for loop
    {
        printf("%d %d \n",i,j);
    }
    
    return 0;
}
