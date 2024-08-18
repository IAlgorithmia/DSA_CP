#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[2][4];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Enter the element of the matrix : ");
            scanf("%d", &a[i][j]); // Remember that a[0][0] se start hoti hai matrix!
        }
        
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", a[i][j]);
        }  
        printf("\n");
    }
    
    int a[10];
    for (int i=0;i<=9;i++){
        printf("Enter the integral number you want to add to the array : ");
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= 9; i++)
    {
        printf("The index %d item of the array is : %d\n", (i+1), a[i]);
    }
    
    return 0;
}
