#include <stdio.h>
int main()
{
    printf("Enter the number of terms in 1st polynomial : \n");
    int i;
    int terms1;
	scanf("%d", &terms1);
    int arr1[terms1];
    printf("Enter the coeffecients : \n");
    for (i = 0; i <= terms1 - 1; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of terms in 2nd polynomial : \n");
    int terms2;
	scanf("%d", &terms2);
    int arr2[terms2];
    printf("Enter the coeffecients : \n");
    for (i = 0; i <= terms2 - 1; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int max = (terms1 > terms2 ? terms1 : terms2);
    int arr3[max];
    int x = 0, y = 0, z = 0;
    for (i = 0; i <= max - 1; i++)
    {
        if (max - z == terms1 - x && max - z == terms2 - y)
        {
            arr3[z] = arr1[x] + arr2[y];
            z++; x++; y++;
        }
        else if (max - z == terms1 - x)
        {
            arr3[z] = arr1[x];
            z++;x++;
        }
        else
        {
            arr3[z] = arr2[y];
            z++; y++;
        }
    }
    printf("\nThe first polynomial is : \n");
    for (i = 0; i <= terms1 - 1; i++)
    {
        if (arr1[i] != 0)
        {
            printf("%dx^%d", arr1[i], terms1 - 1 - i);
        }
        if (i != terms1 - 1)
        {
            if (arr1[i + 1] > 0)
            {
                printf("+");
            }
        }
    }
    printf("\nThe second polynomial is : \n");
    for (i = 0; i <= terms2 - 1; i++)
    {
        if (arr2[i] != 0)
        {
            printf("%dx^%d", arr2[i], terms2 - 1 - i);
        }
        if (i != terms2 - 1)
        {
            if (arr2[i + 1] > 0)
            {
                printf("+");
            }
        }
    }
    printf("\nThe resultant polynomial is : \n");
    for (i = 0; i <= max - 1; i++)
    {
        if (arr3[i] != 0)
        {
            printf("%dx^%d", arr3[i], max - 1 - i);
        }
        if (i != max - 1)
        {
            if (arr3[i + 1] > 0)
            {
                printf("+");
            }
        }
    }
    return 0;
}