#include <stdio.h>
int main(int argc, char const *argv[])
{
    int age, marks;
    printf("Enter your age as an integer : ");scanf("%d",&age);
    printf("Enter your marks as an integer : ");scanf("%d",&marks);
    switch (age)
    {
    case 5:
        printf("Your age is 5 years old\n");
        switch (marks)
        {
        case 95:
            printf("Your marks are : %d", marks);
            break;
        
        default:
            break;
        }
        break;
    case 15:
        printf("Your age is 15 years old");
        break;
    case 25:
        printf("Your age is 25 years old");
        break;
    
    default:
        printf("Your age is not 5, 15 or 25");
        break;
    }
    return 0;
}