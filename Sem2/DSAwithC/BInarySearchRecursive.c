#include <stdio.h>
int bubblesorter(int arr[], int len)
{
    int temp;
    for (int pass = 0; pass < len; pass++)
    {
        for (int j = 0; j < len - 1 - pass; j++)
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
int rebinarysearch(int arr[], int num, int mid, int low, int high)
{
    if (low > high)
    {
        return 0;
    }
    else
    {
        if (num == arr[mid])
        {
            return mid;
        }
        else if (num > arr[mid])
        {
            low = mid + 1;
            mid = (low + high)/2;
            rebinarysearch(arr, num, mid, low, high);
        }
        else
        {
            high = mid - 1;
            mid = (low + high)/2;
            rebinarysearch(arr, num, mid, low, high);
        }
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
    printf("Enter the number you want to search : \n");
    int num;
    scanf("%d", &num);
    bubblesorter(arr, len);
    int low = 0;
    int high = len - 1;
    int mid = (low + high)/2;
    int ans = rebinarysearch(arr, num, mid, low, high);
    if (ans == 0)
    {
        printf("The element wasn't found in the array!");
    }
    else
    {
        printf("The element was found at %d", ans);
    }
    return 0;
}