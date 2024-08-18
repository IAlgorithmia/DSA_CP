#include <stdio.h>
int fibo(int n){
    if (n == 1){
        return 0; 
    }
    else if (n==2){
        return 1;
    }
    else {
        return (fibo(n-1) + fibo(n-2));
    }
}
int main(){
    printf("Enter element number of fibonacci series you want to know : \n");
    int num;
    scanf("%d", &num);
    printf("The element %d of fibonacci series is %d\n", num, fibo(num));
}