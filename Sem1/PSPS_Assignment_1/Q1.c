#include <stdio.h>
int main()
{
    int num, sum = 0;
    printf("Enter the desired length of the array : \n");
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i <= num - 1; i++){
        printf("Enter the number : \n");
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("The sum of the array is : %d", sum);
    return 0;
}