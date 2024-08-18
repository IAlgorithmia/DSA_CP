#include <stdio.h>
int main()
{
    int s,m;
    printf("Did you pass mathematics? (1 for Yes/ 0 for No) : ");scanf("%d", &m);
    printf("Did you pass science? (1 for Yes/ 0 for No) : ");scanf("%d", &s);
    if (s==1 && m==1)
    {
        printf("You've recieved an award of 45 ruppees. Collect from dropdi murmur on Nov 29");
    }
    else if (m==1)
    {
        printf("You've recieved an award of 15 ruppees. Collect from dropdi murmur on Nov 29");
    }
    else if (s==1)
    {
        printf("You've recieved an award of 15 ruppees. Collect from dropdi murmur on Nov 29");
    }
    else
    {
        printf("11th mein arts le lio koi na");
    }
    
    return 0;
}
