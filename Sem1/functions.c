#include <stdio.h>
// This is an inappropriate method, since we're defining a function after calling it. To fix this, we declare the function to just inform the compiler that such a function exists
int sum(int a, int b);
void printstar(int n){
    int i;
    for (i=0;i<=n;i++){
        printf("*\n");
    }
}
int main()
{
    float a,b,c;
    printf("Enter the first number : \n");scanf("%f", &a);
    printf("Enter the second number : \n");scanf("%f", &b);
    c=sum(a,b);
    printstar(7);
    printf("The sum is : %.2f\n", c);
    return 0;
}
int sum(int a, int b){
    printf("My first function is running!\n");
    return a+b;
}