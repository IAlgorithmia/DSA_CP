#include <stdio.h>
struct poly
{
    int coeff;
    int exp;
};
int main()
{
    printf("Enter the highest power of the 1st polynomial : \n");
    int pow1, varr, i;
    scanf("%d", &pow1);
    struct poly poly1[pow1 + 1];
    printf("Enter the coeffecients : \n");
    for (i = 0; i <= pow1; i++)
    {
        scanf("%d", &varr);
        poly1[i].coeff = varr;
        poly1[i].exp = pow1 - i;
    }
    printf("Enter the highest power of the 2nd polynomial : \n");
    int pow2, var;
    scanf("%d", &pow2);
    struct poly poly2[pow2 + 1];
    printf("Enter the coeffecients : \n");
    for (i = 0; i <= pow2; i++)
    {
        scanf("%d", &var);
        poly2[i].coeff = var;
        poly2[i].exp = pow2 - i;
    }
    int max = (pow1 > pow2 ? pow1 : pow2);
    struct poly poly3[max + 1];
    int x = 0, y = 0, z = 0;
    for (i = 0; i <= max; i++)
    {
        if (poly1[x].exp == poly2[y].exp)
        {
            poly3[z].exp = poly1[x].exp;
            poly3[z].coeff = poly1[x].coeff + poly2[y].coeff;
            x++;
            y++;
            z++;
        }
        else if (poly1[x].exp > poly2[y].exp)
        {
            poly3[z].exp = poly1[x].exp;
            poly3[z].coeff = poly1[x].coeff;
            x++;
            z++;
        }
        else
        {
            poly3[z].exp = poly2[y].exp;
            poly3[z].coeff = poly2[y].coeff;
            y++;
            z++;
        }
    }
    printf("The first polynomial is : \n");
    for (i = 0; i <= pow1; i++)
    {
        if (poly1[i].coeff != 0)
        {
            printf("%dx^%d", poly1[i].coeff, poly1[i].exp);
        }
        if (i != pow1)
        {
            if (poly1[i + 1].coeff > 0)
            {
                printf("+");
            }
        }
    }
    printf("\nThe second polynomial is : \n");
    for (i = 0; i <= pow2; i++)
    {
        if (poly2[i].coeff != 0)
        {
            printf("%dx^%d", poly2[i].coeff, poly2[i].exp);
        }
        if (i != pow2)
        {
            if (poly2[i + 1].coeff > 0)
            {
                printf("+");
            }
        }
    }
    printf("\nThe resultant polynomial is : \n");
    for (i = 0; i <= max; i++)
    {
        if (poly3[i].coeff != 0)
        {
            printf("%dx^%d", poly3[i].coeff, poly3[i].exp);
        }
        if (i != max)
        {
            if (poly3[i + 1].coeff > 0)
            {
                printf("+");
            }
        }
    }
    return 0;
}