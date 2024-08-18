#include <stdio.h>
int adder(int *x, int *y){
    return (*x + *y);
}
int subtracter(int *x, int *y){
    return (*x - *y);
}
void swapper(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    printf("Welcome to the swap game\n");
    int a;
    printf("Enter the first value\n");
    scanf("%d", &a);
    int b;
    printf("Enter the second value\n");
    scanf("%d", &b);
    swapper(&a, &b);
    printf("The swapped values are - First Value : %d and Second Value : %d\n", a, b);
    printf("The sum of the two values is : %d\n", adder(&a, &b));
    printf("The difference of the two values is : %d\n", subtracter(&a, &b));
}