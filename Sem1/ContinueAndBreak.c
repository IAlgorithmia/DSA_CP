#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("Hello World\n");
    int age, i;
    for (i=1;i<=10;i++){
        printf("Enter your age : ");
        scanf("%d", &age);
        printf("The age is : %d\n", age);
        if (age<10){
            printf("Daiper badal bc\n");
            continue;
        }
        printf("Hey there %d years old, how you doin'? \n");
    }
    return 0;
}
