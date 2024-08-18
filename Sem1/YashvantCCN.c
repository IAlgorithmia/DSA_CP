#include <stdio.h>
int main(){
    int a;
    printf("Enter the first number : \n");
    scanf("%d", &a);
    int b;
    printf("Enter the second number : \n");
    scanf("%d", &b);
    int c = a/b;
    switch(c){
        case 0:
        printf("%d is greater", b);
        break;
        case 1:
        printf("Both are equal");
        break;
        default:
        printf("%d is greater", a);
        break;

    }
    return 0;
}