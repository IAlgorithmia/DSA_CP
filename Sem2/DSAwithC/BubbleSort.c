#include <stdio.h>
void bubblesorter(int arr[], int len)
{
    int temp, swaps = 0;
    for (int pass = 1; pass < len; pass++)
    {
        for (int j = 0; j < len - pass; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
        if (swaps == 0)
        {
            break;
        }
        swaps = 0;
    }
}
int main()
{
    int len;
    printf("Enter the length of the array : \n");
    scanf("%d", &len);
    int arr[len];
    printf("Enter the elements of the array : \n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubblesorter(arr, len);
    printf("The sorted array is : ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}