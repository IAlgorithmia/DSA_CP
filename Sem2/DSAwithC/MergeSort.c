#include <stdio.h>
void mergesort(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (high + low)/2;
        mergesort(array, low, mid);
        mergesort(array, mid + 1, high);
        merge(array, mid, low, high);
    }
}
void printarray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int mid, int low, int high) //This is actually an internal merger!
{
    int a = low, b = mid + 1, k = low;
    int ansarr[high + 1];
    while (a <= mid && b <= high)
    {
        if (arr[a] < arr[b])
        {
            ansarr[k] = arr[a];
            k++; a++;
        }
        else
        {
            ansarr[k] = arr[b];
            k++; b++;
        }
    }
    while (a <= mid)
    {
        ansarr[k] = arr[a];
        k++; a++;
    }
    while (b <= high)
    {
        ansarr[k] = arr[b];
        k++; b++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = ansarr[i];
    }
}
int main()
{
    int len;
    printf("Enter the number of elements you want to enter : ");
    scanf("%d", &len);
    int array[len];
    printf("Enter the elements : ");
    int i;
    for (i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }
    mergesort(array, 0, len - 1);
    printf("The sorted array is : \n");
    printarray(array, len);
}