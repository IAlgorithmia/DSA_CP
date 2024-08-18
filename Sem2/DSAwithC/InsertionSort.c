#include <stdio.h>
int insertionsorter(int arr[], int len)
{
    int i, j, temp;
    for (i = 1; i < len; i++)
    {
        j = i;
        while (arr[j - 1] > arr[j] && j != 0)
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j = j - 1;
        }
    }
}
int main()
{
    printf("Enter the length of the array : \n");
    int len;
    scanf("%d", &len);
    int i;
    int arr[len];
    printf("Enter the elements of the array : \n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionsorter(arr, len);
    printf("The sorted array is : \n");
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}