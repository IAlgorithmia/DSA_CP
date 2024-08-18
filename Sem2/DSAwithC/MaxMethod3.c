#include <stdio.h>
int max(int *arr, int len)
{
    int max = *arr;
    for (int i = 1; i < len; i++)
    {
        if (max < *(arr + i))
        {
            max = *(arr + i);
        }
    }
    return max;
}
int main()
{
    int n;
    printf("Enter the number of elements you want to enter : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    int maximum = max(arr, len);
    printf("The maximum element in the array is %d", maximum);
    return 0;
}