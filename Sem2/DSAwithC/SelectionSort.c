#include <stdio.h>
int selectionsorter(int arr[], int len)
{
    int i, iteration, index, temp;
    int min;
    for (iteration = 0; iteration < len - 1; iteration++)
    {
        min = arr[iteration];
        for (i = iteration + 1; i < len; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                index = i;
            }
        }
        if (index != iteration)
        {
            temp = arr[index];
            arr[index] = arr[iteration];
            arr[iteration] = temp;
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
    selectionsorter(arr, len);
    printf("The sorted array is : \n");
    for (i = 0; i < len; i++)
    {
        printf(" %d ", arr[i]);
    }
}
