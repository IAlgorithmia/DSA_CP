#include <stdio.h>
int main()
{
    int i;
    i=1;
    printf("First value : %d\nSecond Value : %d\nThird Value : %d", i, i++, ++i); //Whenever the value of i changes, the value of ++i also changes
    return 0;
}
