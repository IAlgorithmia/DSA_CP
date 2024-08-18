#include <stdio.h>
int main()
{
    char str[100];
    int i = 0;
    for (; str[i - 1] != '\n'; i++)
    {
        scanf("%c", &str[i]);
    }
    /*Here, we are using i - 1 because first of all unfilled indeces of str will have garbage 
    values, which will never be equal to \n. Next, I'm actually entering Vaibhav\n, hence I 
    need to check the last element I entered to know whether my string is over or not,  
    becuase otherwise I'll always be checking the unfilled indeces and always having the 
    condition enabled, making the loop not know where to end. str[-1] = garbage value too*/
    str[i] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
    return 0;
}