#include <stdio.h>

// We have to choose between Recursive/Iterative approach when setting out to solve a problem

int factorial(int num){
        if (num == 0 || num == 1){               //these are called as our base cases
            return 1;
        }
        else {
            return (num * (factorial(num-1)));
        }
    }

int main(int argc, char const *argv[])
{
    int a;
    printf("Enter the number you want the factorial of :\n");
    scanf("%d", &a);
    printf("The factorial of %d is %d\n", a, factorial(a));
    return 0;
}
