#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    fgets(str, 1000, stdin);

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i-1]==' ' && str[i] == 't' && str[i + 1] == 'h' && str[i + 2] == 'e' && str[i+3]==' ' || str[i-1]==' ' && str[i] == 'T' && str[i + 1] == 'h' && str[i + 2] == 'e' && str[i+3]==' ' )
        {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}