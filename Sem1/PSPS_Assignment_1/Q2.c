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
    int needed;
    printf("Enter the element you want to search for in the array : \n");
    scanf("%d", &needed);
    for (int i = 0; i <= num - 1; i++){
        if (arr[i]==needed){
            printf("The number is located at the index %d\n",i);
        }
        else {
            continue;
        }
    }
    return 0;
}