#include <stdio.h>

// Recursion mein basically apko 5^k = 5 * 5^k-1 jaise patterns notice karne hain. Repetable steps, that can be executed through the same function.

int expo(int b, int p){
    if (p==0){
        return 1;
    }
    else if (p == 1){
        return b;
    }
    else {
        return b*expo(b,p-1);
    }
}
int main(){
    printf("Enter the number whose power you want to know : \n");
    int base;
    scanf("%d", &base);
    printf("Enter the power you want to raise it to : \n");
    int exp;
    scanf("%d", &exp);
    printf("Answer is %d \n", expo(base,exp));
}