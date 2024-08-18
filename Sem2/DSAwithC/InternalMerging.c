#include <stdio.h>
void internalmerger(int arr[], int mid, int high)
{
    int a = 0, b = mid + 1, c = 0;
    int ansarr[high + 1];
    while (a <= mid && b <= high)
    {
        if (arr[a] < arr[b])
        {
            ansarr[c] = arr[a];
            a++;
            c++;
        }
        else
        {
            ansarr[c] = arr[b];
            c++;
            b++;
        }
    }
    while (a <= mid)
    {
        ansarr[c] = arr[a];
        a++;
        c++;
    }
    while (b <= high)
    {
        ansarr[c] = arr[b];
        b++;
        c++;
    }
    for (int z = 0; z <= high; z++)
    {
        arr[z] = ansarr[z];
    }
}
int main()
{
    printf("Enter the length of the special array : ");
    int len;
    scanf("%d", &len);
    int arr[len];
    printf("Enter the elements : \n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    int mid;
    printf("Enter the index after which partitioning the two sorted arrays is there : ");
    scanf("%d", &mid);
    int low = 0;
    int high = len - 1; 
    internalmerger(arr, mid, high);
    printf("The sorted array is : \n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}