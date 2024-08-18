/*A
  bC
  DeF
  gHiJ
  KlMnO*/
#include <stdio.h>
int main()
{
    int i, j, num, sum, counter = 0;
    printf("Enter the numebr of rows you want to see : \n");
    scanf("%d", &num);
    for (i = 0; i <= num - 1; i++)
    {
        for (j = 0; j <= i; j++)
        {
            sum = i + j;
            if (sum % 2 == 0)
            {
                printf("%c", (65 + counter));
                counter ++;
            }
            else
            {
                printf("%c", (97 + counter));
                counter++;
            }
        }
        printf("\n");
    }
    return 0;
}