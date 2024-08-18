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
    int pos, elem;
    printf("Enter the element to be inserted\n");
    scanf("%d", &elem);
    printf("Enter the index where element is to be inserted\n");
    scanf("%d", &pos);
    int arr1[num+1];
    for (int i = 0; i <= num; i++){
        if (i==pos){
            arr1[i] = elem;
        }
        else if(i<pos){
            arr1[i] = arr[i];
        }
        else{
            arr1[i] = arr[i-1];
        }
    }
    printf("The new array is : \n");
    for (int i = 0; i <= num; i++){
        printf("%d ", arr1[i]);
    }
    return 0;
}