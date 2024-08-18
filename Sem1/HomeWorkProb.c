#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sub1, sub2, sub3, sub4, sub5, perc;
    printf("Enter the marks in subject 1 : ");scanf("%d",&sub1);
    printf("Enter the marks in subject 2 : ");scanf("%d",&sub2);
    printf("Enter the marks in subject 3 : ");scanf("%d",&sub3);
    printf("Enter the marks in subject 4 : ");scanf("%d",&sub4);
    printf("Enter the marks in subject 5 : ");scanf("%d",&sub5);
    perc=((sub1+sub2+sub3+sub4+sub5)/5);
    if (perc>=60){
        printf("Category 1");
    }
    else if (perc>=50)
    {
        printf("Category 2");
    }
    else if (perc>=40)
    {
        printf("Category 3");
    }
    else
    {
        printf("You haven't Passed");
    }
    
    return 0;
}
