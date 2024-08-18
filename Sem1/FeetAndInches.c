#include <stdio.h>
struct dist
{
    int feet;
    int inches;
};
struct dist add(struct dist x, struct dist y)
{
    struct dist z;
    z.feet = x.feet + y.feet;
    if (x.inches + y.inches >= 12)
    {
        z.feet += ((x.inches + y.inches) / 12);
    }
    z.inches = (x.inches + y.inches) % 12;
    return z;
}
int main()
{
    struct dist h1, h2, h3;
    printf("Enter height 1 : \n");
    scanf("%d %d", &h1.feet, &h1.inches);
    printf("Enter height 2 : \n");
    scanf("%d %d", &h2.feet, &h2.inches);
    h3 = add(h1, h2);
    printf("The sum of these heights is : %d %d", h3.feet, h3.inches);
    return 0;
}