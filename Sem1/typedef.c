#include <stdio.h>
typedef struct student //this is the actual use of typedef, notice that the syntax for typedef remains the same, ie, typedef datatype_definition alias_name
{
    int id;
    int marks;
    char fav_char;
    char name[100];
} std;
int main()
{
    struct student p1;
    p1.id = 56;
    std p2;
    p2.id = 88;
    printf("The value of p1's ID is %d\n", p1.id);
    printf("The value of p2's ID is %d\n", p2.id);
    // typedef data_type alias_name
    typedef unsigned long ul;
    ul a, b, c, d;
    typedef int integer;
    integer x = 3;
    printf("The value of x is %d", x);
    int c = 88;
    int* a, b; //This is treadted as int *a, b; whereas we want to make both of them as pointers
    a = &c;
    b = c; //These two are correct here 
    typedef int* intpointer;
    intpointer a, b;
    a = &c;
    b = &c; //These two are correct here  
    return 0;
}