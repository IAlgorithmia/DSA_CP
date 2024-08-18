#include <stdio.h>
#include <string.h>
union student
{
    int id;
    int marks;
    char fav_char;
    char name[50];
};
int main()
{
    union student S;
    S.id = 44;
    S.marks = 55;
    S.fav_char = 'U';
    strcpy(S.name, "Jesus Christ"); //The detail that's given at the last is presderved and thers are discarded becuase union to ek hi use karne dega na at a time  
    printf("Detail 1 is %d\n", S.id);
    printf("Detail 2 is %d\n", S.marks);
    printf("Detail 3 is %c\n", S.fav_char);
    printf("Detail 4 is %s\n", S.name);
    return 0;
}