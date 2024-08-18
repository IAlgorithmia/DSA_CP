#include <stdio.h>
int max(int *ptr, int len)
{
    int max = *ptr;
    for (int i = 1; i < len; i++)
    {
        if (max < *(ptr + i))
        {
            max = *(ptr + i);
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
    int *ptr = arr;
    printf("Enter the elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (ptr + i));
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    int maximum = max(ptr, len);
    printf("The maximum element in the array is %d", maximum);
    return 0;
}