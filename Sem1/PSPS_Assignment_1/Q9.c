#include <stdio.h>
int main()
{
    int num;
    printf("Enter the desired length of the array : \n");
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i <= num - 1; i++){
        printf("Enter the number : \n");
        scanf("%d", &arr[i]);
    }
    int arr1[num];
    for (int i = 0; i <= num - 1; i++){
        arr1[i] = arr[num-1-i];
    }
    printf("The new array is : \n");
    for (int i = 0; i <= num - 1; i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}