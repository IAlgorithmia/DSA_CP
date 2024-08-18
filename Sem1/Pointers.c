#include <stdio.h>
int main(){
    int a = 69;
    int *ptr = &a;
    int *ptr2 = NULL;
    printf("The value of a is %d, i.e. %d\n", a, *ptr);
    printf("The address of a is %p\n", &a);
    printf("The address of a is %p\n", ptr);
    printf("The value of ptr is %d\n", ptr); //Garbage Value
    printf("The address of ptr is %p\n", &ptr);
    printf("The address to which a null pointer ptr2 is pointing is %p\n", ptr2);
    printf("The address of ptr2 is %p\n", &ptr2);
    // %p is used for getting the address printed by pointers via printf. Prefer 
    // this over %x, which is for recieveing addresses in hexadecimal 
    return 0;
}