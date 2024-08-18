#include <stdio.h>
void printer(int **a)
{
    printf("%d\n", **a);
    (**a)++;
    printf("%d\n", **a);
}
int main()
{
    int a = 5;
    int *b;
    b = &a;
    int **c;
    c = &b;
    printer(c);
    printf("%d\n", a);
    return 0;
}