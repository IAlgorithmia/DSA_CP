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
    for (int i = 0; i <= num - 1; i++){
        for (int j = 0; j <= num - 1; j++){
            if (arr[i] > arr[j]){
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
    printf("The new array is : \n");
    for (int i = 0; i <= num - 1; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}