#include <stdio.h>
#include <string.h>
struct student 
{
    char name[100];
    int rollno; 
    int age;
};
int main()
{
    printf("Entering the details of 10 students and displaying them\n");
    struct student P[10];\
    printf("Enter name then rollno then age\n");
    for (int i = 0; i <= 9; i++)
    {
        scanf("%s %d %d", &P[i].name, &P[i].rollno, &P[i].age);
    }
    for (int i = 0; i <= 9; i++)
    {
        printf("%s %d %d\n", P[i].name, P[i].rollno, P[i].age);
    }
    return 0;
}