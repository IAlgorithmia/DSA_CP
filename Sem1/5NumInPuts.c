#include <stdio.h>
int main(){
    int count = 0;
    int arr[5];
    while (count != 5){
        int input;
        printf("Enter the number :\n");
        scanf("%d", &input);
        if ( input <= 20){
            arr[count] = input;
            count ++;
        }
        else {
            printf("Enter a valid input\n");
        }
    }
    int sum = 0;
    for (int i = 0; i<= 4; i++){
        sum = sum + arr[i];
        printf("The sum is %d\n", sum);
    }
    printf("The average of the numbers is %.2f", sum/5.0);
}