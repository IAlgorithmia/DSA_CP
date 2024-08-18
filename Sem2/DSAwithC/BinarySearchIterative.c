#include <stdio.h>
int bubblesorter(int arr[], int len)
{
    int temp;
    for (int pass = 1; pass < len; pass++)
    {
        for (int j = 0; j < len - pass; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int itbinarysearch(int arr[], int num, int len)
{
    int low = 0; int high = len - 1;
    int mid;
    while (1)
    {
        mid = (low + high)/2;
        if (num == arr[mid])
        {
            return mid;
        }
        else if (num > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
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
    printf("Enter the number you want to search : \n");
    int num;
    scanf("%d", &num);
    bubblesorter(arr, len);
    int ans = itbinarysearch(arr, num, len);
    if (ans == 0)
    {
        printf("The element was not found in the array!");
    }
    else
    {
        printf("The element was found at %d", ans);
    }
    return 0;
}