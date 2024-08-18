#include <stdio.h>
int main(){
    printf("Welcome to the ascii info\n");
    for (int i=65;i<=90;i++){
        printf("The character of ascii code %d is %c\n", i, i);
    }
    printf("Here's your smiling face : %c", 1);
    return 0;
}