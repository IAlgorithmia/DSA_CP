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
    struct student p;
    struct student *p1;
    strcpy(p.name, "Jesus");
    p.rollno = 55;
    p.age = 23;
    p1 = &p;
    printf("The details are - name = %s, rollno = %d, age = %d", p1->name, p1->rollno, p1->age);
    return 0;
}