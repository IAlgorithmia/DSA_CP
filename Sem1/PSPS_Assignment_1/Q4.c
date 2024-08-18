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
    int pos;
    printf("Enter the index of the element to be deleted\n");
    scanf("%d", &pos);
    int arr1[num-1];
    for (int i = 0; i <= num-1; i++){
        if (i==pos){
            continue;
        }
        else if(i<pos){
            arr1[i] = arr[i];
        }
        else{
            arr1[i-1] = arr[i];
        }
    }
    printf("The new array is : \n");
    for (int i = 0; i <= num - 2; i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}