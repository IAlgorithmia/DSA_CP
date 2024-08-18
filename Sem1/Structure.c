#include <stdio.h>
#include <string.h> //For using strings in the structure
struct student
{
    int id;
    int marks;
    char fav_char;
    char name[100];
} harry, ravi, shubham;
// struct student harry, ravi, shubham; This can be done too
int main()
{
    harry.id = 1;
    ravi.id = 2;
    shubham.id = 3;
    strcpy(harry.name, "Harish Bhai"); // Very important you can't do harry.name = "Hello Bhai"
    strcpy(ravi.name, "Ravi Bhai");
    strcpy(shubham.name, "Shubham Bhai");
    harry.marks = 98;
    ravi.marks = 99;
    shubham.marks = 100;
    harry.fav_char = 'H';
    ravi.fav_char = 'R';
    shubham.fav_char = 'S';
    printf("Harry got %d marks, his ID is %d, his fav char is %c, his true name is %s\n\n", harry.marks, harry.id, harry.fav_char, harry.name);
    printf("Ravi got %d marks, his ID is %d, his fav char is %c, his true name is %s\n\n", ravi.marks, ravi.id, ravi.fav_char, ravi.name);
    printf("Shubham got %d marks, his ID is %d, his fav char is %c, his true name is %s\n\n", shubham.marks, shubham.id, shubham.fav_char, shubham.name);
    return 0;
}